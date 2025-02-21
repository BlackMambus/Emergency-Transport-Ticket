#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

// Class to represent an emergency transport ticket
class EmergencyTransportTicket {
public:
    std::string transportType;
    std::string departurePlace;
    std::string destinationPlace;
    std::string ticketNumber;
    std::string issueTime;
    float fare;

    // Constructor
    EmergencyTransportTicket(std::string transport, std::string departure, std::string destination) {
        transportType = transport;
        departurePlace = departure;
        destinationPlace = destination;
        ticketNumber = generateTicketNumber();
        issueTime = getCurrentTime();
        fare = calculateFare();
    }

    // Function to generate a unique ticket number
    std::string generateTicketNumber() {
        srand(time(0)); // Seed random number generator
        int randNum = rand() % 10000; // Generate a random number
        return "TKT" + std::to_string(randNum);
    }

    // Function to get current time
    std::string getCurrentTime() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        return std::string(buf);
    }

    // Function to calculate the fare based on distance (simplified)
    float calculateFare() {
        int distance = rand() % 50 + 10; // Random distance between 10 and 60 km
        return distance * 2.5; // Fare per km is 2.5
    }

    // Function to display the ticket information
    void displayTicket() {
        std::cout << "\n------- Emergency Transport Ticket -------\n";
        std::cout << "Ticket Number: " << ticketNumber << std::endl;
        std::cout << "Transport Type: " << transportType << std::endl;
        std::cout << "Departure: " << departurePlace << std::endl;
        std::cout << "Destination: " << destinationPlace << std::endl;
        std::cout << "Issue Time: " << issueTime << std::endl;
        std::cout << "Fare: $" << std::fixed << std::setprecision(2) << fare << std::endl;
        std::cout << "------------------------------------------\n";
    }
};

int main() {
    std::string transportType;
    std::string departurePlace;
    std::string destinationPlace;

    // Take input for the emergency transport
    std::cout << "Enter the type of transport (e.g., Ambulance, Emergency Vehicle): ";
    std::getline(std::cin, transportType);
    std::cout << "Enter the departure place: ";
    std::getline(std::cin, departurePlace);
    std::cout << "Enter the destination place: ";
    std::getline(std::cin, destinationPlace);

    // Create an emergency transport ticket object
    EmergencyTransportTicket ticket(transportType, departurePlace, destinationPlace);

    // Display the generated ticket
    ticket.displayTicket();

    return 0;
}







