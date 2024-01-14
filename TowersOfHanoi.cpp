/** 
 * Project - Towers of Hanoi (Non-recursive)
 * */

#include <iostream>
#include <vector>
using namespace std;
int main() { //everything is in one main function 
  
  vector<int> t[3]; //three towers A,B,C represented as an array of 3 vectors
  int n, candidate=1, to, from=0, moves=0; //Initialize the variables
  cout << "Enter the number of rings:"; //ask the user to enter the # of rings
  cin >> n; //store the input
  cout << endl;
   
   //Reference:
   //push_back add element to the end
   //pop_back delete the last element
   //back access the last element
  //.size() returns th size of the vector

   //to check if n is even or odd
  bool even = false;
  if(n%2==0) even = true; //use mod to determine
  
  //Initialize the 3 towers. 
  //t[0] is tower 0 or A
  //t[2] is tower 2 or B
  //t[3] is tower 3 or C
  for (int i=n+1; i>=1; i--){t[0].push_back(i);}
     t[1].push_back(n+1); //put the 4's on tower 1 and generalize to n+1 
     t[2].push_back(n+1); //put the 4's on tower 2 and generalize to n+1 
  
  if(even) to = 2; //if we have an even # of rings, our initial to tower will be set to 2
  else to = 1; //otherwise it will be 1
  t[from].back(); //candidate (t[from].back()) is the ring to be moved 
  
    //now we loop while when there are still rings to transfer tower B (t[1]) and we will the size of tower B and continue to loop until it reaches n+1
    while(t[1].size()<n+1){ //and t[1] does not include all the rings on it
    //now we are printing the move while incrementing it, transferring the ring, and moving the candidate from (FROM tower) to (TO tower) using the ASCII table.
    cout << "Move number" << ++moves << ": Transfer ring " << candidate << " from tower " << char(from + 65) << " to tower "<< char(to + 65) << endl;
     
     //now we move the rings from our FROM tower and place it on To tower 
    t[to].push_back(t[from].back()); //push the ring onto the TO tower
    t[from].pop_back(); //then remove the ring from the FROM tower
    
    //now we need to get to the next FROM tower
    //the candidate is the smallest ring available here that wasn't moved 
    //it cannot be the most recent TO tower
    if (t[(to+1)%3].back() < t[(to+2)%3].back()) //if the (to+1) tower has the smallest ring than (to + 2) then do a comparision
    from=(to+1)%3; //then our FROM tower becomes to + 1, if that ring is smaller
    else from=(to+2)%3; //otherwise it will be (to + 2) 
    //assign FROM to be whichever tower has the smallest ring.
    
    //now we need to get the next candidate
    candidate=t[from].back(); //the ring to be moved which is the top ring from the FROM tower (using the from tower and the back function)
    
    //now finding the next to tower will depend on if we are dealing with odd or even
    //we do this to move to the left if it's an even number of rings
    //or to the right if it is odd number
    even = n%2==1; //set the even 
    if (even) { //check for even
      if (candidate < t[(from+1)%3].back()) //take the candidate and compare it to the back 
      to=(from+1)%3; //form +1 is when the tower is moving to the right
      else to=(from+2)%3; //for even is +2
    }
    else { //else check for odd
      if(candidate < t[(from+2)%3].back()) //take the candidate and compare it to the back 
      to=(from+2)%3; //form +2 is when the tower is moving to the left
      else to=(from+1)%3; //for odd is +1
    }
  } return 0;
}