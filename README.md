**Train Ticket Reservation System**

A simple console-based train ticket reservation system written in C. This project includes features for reserving, canceling, and viewing seat reservations, with a special priority for elderly passengers, pregnant women, and passengers with children to be assigned lower berths.

Features

View Available Seats: Display all seats that are currently available for reservation.

Reserve a Seat:

Assigns lower berths to:

Passengers aged 55 or above.

Pregnant women.

Passengers with children.

Assigns general seats if no lower berths are available.

Cancel a Reservation: Free up a previously reserved seat.

View Reserved Seats: Display all reserved seats along with passenger details (name, age, and special conditions).

**How It Works**

The system maintains an array of 100 seats, where:

The first 20 seats are considered lower berths.

The remaining 80 seats are general seats.

The program prioritizes assigning lower berths to eligible passengers based on age or special conditions.
