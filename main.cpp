#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>

#include "FileMethods.h"
#include "TimeMethods.h"
using namespace std;

int main() {
    // file stuff
    ofstream writeFile("file.txt");
    ifstream readFile("file.txt");

    file->writeInput(writeFile);
    file->read(readFile);

    // time stuff
    t->printTimestamp(t->getCurrentTimestamp());

    /* Vectors
    * It's like a resizable array. Like arrays, it must store the same data type
    */

   vector<string> animals = {"cat", "dog", "fish", "panda", "bear", "bird"};
   cout << animals[animals.size() - 1] << endl;
   cout << animals.back() << endl;
   cout << animals[0] << endl;

   // change 1st element to the 2nd element
   string temp = animals[0];
   animals[0] = animals[1];
   animals[1] = temp;
   cout << animals.front() << endl;

   try {
    // .at() is preferred over indexing [] because it throws an error when out of bounds
    cout << animals.at(animals.size());
   } catch (const out_of_range& E) {
    cout << E.what() << endl;
   }

    // add element to the back
    animals.push_back("gecko");
    
    // remove element from the back
    animals.pop_back();

    // remove every element from the vector, then check if it is empty
    for (int i = animals.size() - 1; i >= 0; i--) {
        animals.pop_back();
    }
    // 1 for empty, 0 for not
    cout << animals.empty() << endl;


    /* Lists
    * Similar to a vector, lists are resizable.
    * However, lists offer utility when adding new elements.
    * Lists do not support accessing elements by index.
    * You can loop through a list with a for each loop or an iterator
    */
    
    list<string> cars = {"Honda", "Toyota", "BMW", "Volkwagon", "Ford"};

    // Cannot index using []
    cout << cars.front() << endl;
    cout << cars.back() << endl;

    // Change element with .front() or .back()
    cars.front() = "Mazda";

    // Add to back and front
    cars.push_back("Honda");
    cars.push_front("Hyundai");

    // Remove from back and front
    cars.pop_back();
    cars.pop_front();

    // Size of list
    cout << cars.size() << endl;

    /* Stacks (LIFO)
    * No indexing []
    * Elements added and removed from the top
    * Cannot declare with items
    */
    stack<string> phones;
    // bottom 
    phones.push("Apple");
    phones.push("Samsung");
    phones.push("Nokia");

    // top
    phones.push("Google");

    // Access the top element with .top()
    cout << phones.top() << endl;

    // Remove element from the stack
    phones.pop();

    // Size of the stack
    cout << phones.size() << endl;

    /* Queues (FIFO)
    * No indexing []
    * Elements added to end and removed from beginning
    * Cannot declare with items
    */

    queue<string> groceries;

    // Front
    groceries.push("cabbage");
    groceries.push("carrots");
    groceries.push("chips");

    // Back
    groceries.push("peanut butter");

    cout << groceries.front() << endl;
    cout << groceries.back() << endl;

    // Remove front element
    groceries.pop();

    cout << groceries.size() << endl;

    /* Deques (Double ended queue) 
    * Indexing allowed
    * Elements can be added and removed from both sides
    * Can declare with items
    */

    deque<string> people = {"Ethan", "Eva", "Dylan", "Jacob", "Sophia"};

    // front and back work, indexing as well
    temp = people[0];
    people[0] = people.back();
    people[people.size() - 1] = temp;

    // .at() works too
    cout << people.at(2) << endl;

    people.push_back("Nahee");
    people.pop_back();
    people.push_front("Ethan");
    people.pop_back();

    // You can use .empty() and .size()

    /* Sets
    * Each element is unique and sorted
    * Sorted automatically in ascending order
    * No indexing []
    */

    set<string> bodyParts = {"head", "feet", "arms", "stomach"};
    // the elements will be automatically sorted alphabetically

    for (string part : bodyParts) {
        cout << part << endl;
    }

    // set in descending order
    set<string, greater<string>> bodyParts2 = {"head", "feet", "arms", "stomach"};

    bodyParts.insert("knee");
    bodyParts.erase("feet");
    bodyParts2.clear();
    cout << bodyParts2.size() + " " << bodyParts2.empty() << endl;

    /* Maps
    * Key/value pairs
    * Access via keys
    * Keys sorted in ascending order
    */

   // reverse with map<string, int, greater<string>>
    map<string, int> roles = {{"admin", 1}, {"co-admin", 2}, {"user", 56}};

    // You can use [] or .at()
    cout << "There are " << roles["admin"] << " admins" << endl;
    cout << "There are " << roles.at("co-admin") << " co-admins" << endl;

    // Change existing element
    roles["admin"] = 2;

    // Add new element
    roles["moderator"] = 3;
    roles.insert({"bot", 6});

    // Remove elements
    roles.erase("moderator");

    // Check if an element exists (1 for yes, 0 for no)
    cout << roles.count("moderator");

    // LOOPING through a map
    for (auto role : roles) { // he auto keyword detects the data type for each key/value pair
        cout << role.first << " is: " << role.second << endl;
    }

    // Remove all elements
    roles.clear();

    // Print out the size (0) and if it's empty (1)
    cout << roles.size() << endl << roles.empty() << endl;

    /* Iterators
    * When you need to add or remove elements during iteration, iterate in reverse, or skip elements, you should use iterators
    * Works for vectors, lists, deques, sets and maps
    * Doesn't work for stacks and queues
    */

    animals = {"cat", "dog", "fish", "panda", "bear", "bird"};
    vector<string>::iterator it;
    // alternatively,
    // auto it = animals.begin();

    // iterate in reverse with .rbegin() and .rend()
    for (it = animals.begin(); it != animals.end(); ++it) {
        cout << *it << endl;
    }

    // .begin() gives us a pointer to the first element
    // .begin() + 1 gives us a pointer to the second element
    // .end() - 1 gives us a pointer to the last element

    // Map example
    roles = {{"admin", 1}, {"co-admin", 2}, {"user", 56}};
    
    for (auto it = roles.begin(); it != roles.end(); ++it) {
        // it->first = (*it).first
        cout << it->first << " is: " << it->second << "\n";
    }

    // Algorithms

    sort(animals.begin(), animals.end());
    for (it = animals.begin(); it != animals.end(); ++it) {
        cout << *it << endl;
    }

    // Search for an element
    auto it = find(roles.begin(), roles.end(), "user");
    cout << *it;

    // To search for an element that is greater than a certain value, use upper_bound()
    // Consider if sorting is important to this procedure
    deque<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 15};
    auto it = upper_bound(nums.begin(), nums.end(), 10);
    cout << *it;

    // use min_element() to get the smallest value
    // use max_element() to get the largest value

    // Use copy() to copy a data structure
    deque<int> numsCopy(16);
    copy(nums.begin(), nums.end(), numsCopy.begin());

    // Fill a data structure with values with fill()
    fill(nums.begin(), nums.end(), 0);

    // Random (uses <cstdlib>)

    // Random number 0 - 100
    int randomNum = rand() % 101;

    // Random number 1 - 100
    int randomNum = rand() % 100 + 1;

    // CMATH: https://www.w3schools.com/cpp/cpp_ref_math.asp
    // Example programs: https://www.w3schools.com/cpp/cpp_examples.asp
}