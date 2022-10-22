# OOP 345 (C++ Programming 2, Grade: A+)
- Design collections of model objects using sequential containers and multi-dimensional arrays to solve a systems or business problem
- Create function objects and closures to customize a programming solution for a particular application
- Model generalization and specialization using inheritance hierarchies to minimize the duplication of code
- Model polymorphic behavior using interfaces, virtual functions and templates (generics) to amplify the reusability of code
- Implement design components using algorithms of the standard template library to utilize existing technologies
- Create program components of quadratic complexity to solve non-linear problems
- Design program components using raw pointers and pointer arithmetic to access data in program memory
- Design multi-tasked solutions using threading libraries to improve the performance of a program
- Design file stream objects to backup text and binary data for future restoration


# AssemblyStation-Project (Academic project: OOP345, Grade: A+)

## Milestone 1
### Utilities and Station classes
Milestone 1 implements and tests the `Utilities` and `Station` modules.

The `Utilities` module supports the parsing of input files, which contain information used to setup and configure the assembly line.
The `Station` module manages information about a station on the assembly line, which holds a specific item and fills customer orders.

## Milestone 2
Milestone 2 implements and tests the `CustomerOrder` module.

The `CustomerOrder` module contains all the functionality for processing customer orders as they move from `Station` to `Station` along
the assembly line. The `Station` where a given order currently rests fills a request for one item of that station, if there is any such request.

## Milestone 3
Milestone 3 implements and tests the `Workstation` and `LineManager` modules.

The `LineManager` module first configures the assembly line and then moves `CustomerOrders` along it (from start to finish). The `LineManager` object
configures the `Workstation` objects identified by the user, and moves orders along the line one step at a time. A `Workstation` is a `Station` that 
the `LineManager` has activated on the user's request. At each step, every `Workstation` fills one item in a `CustomerOrder`, if possible. The manager
moves orders from station to station. Once an order has reached the end of the line, it is either complete or incomplete. An order is incomplete
if one or more stations had an insufficient number of items in stock to cover that order's requests.

