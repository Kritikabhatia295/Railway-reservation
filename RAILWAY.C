#include <stdio.h>

// Define a maximum number of seats per train
#define MAX_SEATS 5

// Structure to store train information
struct Train {
    char name[30];
    int availableSeats;
};

void displayTrains(struct Train trains[], int n) {
    printf("\nAvailable Trains:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - Available seats: %d\n", i + 1, trains[i].name, trains[i].availableSeats);
    }
}

void reserveSeat(struct Train *train) {
    if (train->availableSeats > 0) {
        train->availableSeats--;
        printf("Ticket reserved successfully! Remaining seats: %d\n", train->availableSeats);
    } else {
        printf("Sorry, no available seats on this train.\n");
    }
}

int main() {
    struct Train trains[3] = {
        {"Express Train", MAX_SEATS},
        {"Fast Train", MAX_SEATS},
        {"Local Train", MAX_SEATS}
    };

    int choice;
    int continueBooking = 1;

    while (continueBooking) {
        displayTrains(trains, 3);

        printf("\nEnter the number of the train you want to book a seat on (1-3): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please select a number between 1 and 3.\n");
        } else {
            reserveSeat(&trains[choice - 1]);
        }

        // Ask if the user wants to make another reservation
        printf("\nDo you want to make another reservation? (1 for Yes, 0 for No): ");
        scanf("%d", &continueBooking);
    }

    printf("\nThank you for using the ticket reservation system.\n");

    return 0;
}