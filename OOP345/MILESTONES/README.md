# AssemblyStation-Project (C++ Academic project: OOP345, Grade: A+)

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

