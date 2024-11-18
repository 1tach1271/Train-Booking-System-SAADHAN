
#include <stdio.h>
#include <string.h>

#define MAX_SEATS 100
#define LOWER_BERTH_LIMIT 20

typedef struct {
    int seat_number;
    char passenger_name[50];
    int age;
    char special_condition[20];
    int is_reserved;
} Seat;

Seat seats[MAX_SEATS];

void initializeSeats() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seat_number = i + 1;
        seats[i].is_reserved = 0;
        strcpy(seats[i].special_condition, "None");
    }
}

void displayAvailableSeats() {
    printf("Available Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (!seats[i].is_reserved) {
            printf("Seat %d\n", seats[i].seat_number);
        }
    }
}

int findLowerBerth() {
    for (int i = 0; i < LOWER_BERTH_LIMIT; i++) {
        if (!seats[i].is_reserved) {
            return i;
        }
    }
    return -1;
}

int findGeneralSeat() {
    for (int i = LOWER_BERTH_LIMIT; i < MAX_SEATS; i++) {
        if (!seats[i].is_reserved) {
            return i;
        }
    }
    return -1;
}

void reserveSeat() {
    int age;
    char name[50], special_condition[20];
    printf("Enter passenger name: ");
    scanf("%s", name);
    printf("Enter passenger age: ");
    scanf("%d", &age);
    printf("Special condition (Pregnant/Child/None): ");
    scanf("%s", special_condition);

    int seat_index = -1;
    if (age > 55 || strcmp(special_condition, "Pregnant") == 0 || strcmp(special_condition, "Child") == 0) {
        seat_index = findLowerBerth();
        if (seat_index == -1) {
            printf("No lower berths available. Assigning general seat.\n");
            seat_index = findGeneralSeat();
        }
    } else {
        seat_index = findGeneralSeat();
    }

    if (seat_index == -1) {
        printf("No seats available.\n");
        return;
    }

    seats[seat_index].is_reserved = 1;
    strcpy(seats[seat_index].passenger_name, name);
    seats[seat_index].age = age;
    strcpy(seats[seat_index].special_condition, special_condition);
    printf("Seat %d reserved for %s.\n", seats[seat_index].seat_number, name);
}

void cancelReservation() {
    int seat_number;
    printf("Enter seat number to cancel: ");
    scanf("%d", &seat_number);
    if (seat_number < 1 || seat_number > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (!seats[seat_number - 1].is_reserved) {
        printf("Seat is not reserved.\n");
        return;
    }
    seats[seat_number - 1].is_reserved = 0;
    printf("Reservation for seat %d cancelled.\n", seat_number);
}

void displayReservedSeats() {
    printf("Reserved Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i].is_reserved) {
            printf("Seat %d - %s (Age: %d, Condition: %s)\n", seats[i].seat_number, seats[i].passenger_name, seats[i].age, seats[i].special_condition);
        }
    }
}

int main() {
    int choice;
    initializeSeats();
    do {
        printf("\nTrain Ticket Reservation System\n");
        printf("1. Display Available Seats\n");
        printf("2. Reserve a Seat\n");
        printf("3. Cancel Reservation\n");
        printf("4. Display Reserved Seats\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayAvailableSeats();
                break;
            case 2:
                reserveSeat();
                break;
            case 3:
                cancelReservation();
                break;
            case 4:
                displayReservedSeats();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}
