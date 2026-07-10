# Vehicle Registry System 🚗✈️

This is a mini project I made in C++ to practice Inheritance (OOP concept). It is a console-based Vehicle Registry System where you can add vehicles, view all of them, search by ID, and also see a demo of different types of inheritance.

## What this project does

- Add a new vehicle (ID, manufacturer, model, year)
- View all vehicles added so far
- Search a vehicle by its ID
- Demonstrate inheritance using different vehicle types (Sports Car, Flying Car, Sedan, SUV)
- Exit the program

## Concepts used

- Class and Objects
- Single Inheritance → `Car` inherits from `Vehicle`
- Multilevel Inheritance → `ElectricCar` → `Car` → `Vehicle`, and `SportsCar` → `ElectricCar`
- Multiple Inheritance → `FlyingCar` inherits from both `Car` and `Aircraft`
- Hierarchical Inheritance → `Sedan` and `SUV` both inherit from `Car`
- Static member (to count total vehicles)
- Arrays of objects
- Switch case and do-while loop for the menu

## Files in this project

```
pr-3-c++/
├── pr-3.cpp        -> main source code
├── a.exe           -> compiled output (Windows)
├── output-1.png    -> screenshot of program output
└── output-2.png    -> screenshot of program output
```

## How to run

1. Make sure you have a C++ compiler installed (g++ works fine).
2. Open terminal in the `pr-3-c++` folder.
3. Compile the code:
   ```
   g++ pr-3.cpp -o output
   ```
4. Run it:
   ```
   ./output
   ```
5. Follow the menu options shown on screen. Try option 4 to see all the inheritance types in action.

## Sample Output

Check `output-1.png` and `output-2.png` in this repo to see how the program looks when it runs.

