#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <thread>
#include <fstream>
#include <iomanip>
#include <limits>

// Class definitions
class Club {
private:
    std::string name;
    std::string description;

public:
    Club(const std::string& name, const std::string& description)
        : name(name), description(description) {}

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
};

class Event {
private:
    std::string name;
    std::string date;
    std::string description;
    std::string clubName;

public:
    Event(const std::string& name, const std::string& date,
          const std::string& description, const std::string& clubName)
        : name(name), date(date), description(description), clubName(clubName) {}

    std::string getName() const { return name; }
    std::string getDate() const { return date; }
    std::string getDescription() const { return description; }
    std::string getClubName() const { return clubName; }
};

class CampusConnect {
private:
    std::vector<Club> allClubs;
    std::vector<Event> allEvents;
    std::vector<Club> joinedClubs;

    // Helper functions
    void clearScreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void displayHeader() {
        std::cout << "\n";
        std::cout << "╔═══════════════════════════════════════════════════════════╗\n";
        std::cout << "║                     CAMPUS CONNECT                        ║\n";
        std::cout << "║              College Club Collaboration Platform          ║\n";
        std::cout << "╚═══════════════════════════════════════════════════════════╝\n\n";
    }

    void displayAnimation() {
        std::cout << "Loading";
        for (int i = 0; i < 5; i++) {
            std::cout << ".";
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        std::cout << "\n";
    }

    void waitForEnter() {
        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
    }

    bool isClubJoined(const std::string& clubName) {
        for (const auto& club : joinedClubs) {
            if (club.getName() == clubName) {
                return true;
            }
        }
        return false;
    }

    void saveJoinedClubs() {
        std::ofstream file("joined_clubs.txt");
        if (file.is_open()) {
            for (const auto& club : joinedClubs) {
                file << club.getName() << "\n";
            }
            file.close();
        }
    }

    void loadJoinedClubs() {
        std::ifstream file("joined_clubs.txt");
        std::string clubName;

        if (file.is_open()) {
            while (getline(file, clubName)) {
                for (const auto& club : allClubs) {
                    if (club.getName() == clubName) {
                        joinedClubs.push_back(club);
                        break;
                    }
                }
            }
            file.close();
        }
    }

public:
    CampusConnect() {
        // Initialize clubs
        allClubs.push_back(Club("Coding Club", "Learn programming and build cool projects"));
        allClubs.push_back(Club("Dance Club", "Express yourself through various dance forms"));
        allClubs.push_back(Club("Drama Club", "Develop acting skills and perform in plays"));
        allClubs.push_back(Club("Sports Club", "Participate in various sports activities"));
        allClubs.push_back(Club("Music Club", "Learn instruments and perform in concerts"));
        allClubs.push_back(Club("Art Club", "Express creativity through various art forms"));
        allClubs.push_back(Club("Debate Club", "Develop public speaking and argumentation skills"));

        // Initialize events
        allEvents.push_back(Event("Hackathon 2023", "2023-11-15", "24-hour coding competition", "Coding Club"));
        allEvents.push_back(Event("Dance Showcase", "2023-11-20", "Annual dance performance", "Dance Club"));
        allEvents.push_back(Event("Romeo & Juliet", "2023-12-05", "Shakespeare's classic play", "Drama Club"));
        allEvents.push_back(Event("Basketball Tournament", "2023-11-25", "Inter-college basketball competition", "Sports Club"));
        allEvents.push_back(Event("Rock Concert", "2023-12-10", "Live band performance", "Music Club"));
        allEvents.push_back(Event("Art Exhibition", "2023-12-15", "Display of student artwork", "Art Club"));
        allEvents.push_back(Event("Debate Competition", "2023-11-30", "Inter-college debate tournament", "Debate Club"));
        allEvents.push_back(Event("Code Workshop", "2023-12-02", "Learn web development basics", "Coding Club"));
        allEvents.push_back(Event("Football Match", "2023-12-08", "Friendly match with State University", "Sports Club"));

        // Load previously joined clubs
        loadJoinedClubs();
    }

    ~CampusConnect() {
        // Save joined clubs when program exits
        saveJoinedClubs();
    }

    void start() {
        clearScreen();
        displayHeader();
        displayAnimation();

        mainMenu();
    }

    void mainMenu() {
        int choice;
        bool running = true;

        while (running) {
            clearScreen();
            displayHeader();

            std::cout << "╔═══════════════════════════════╗\n";
            std::cout << "║           MAIN MENU           ║\n";
            std::cout << "╚═══════════════════════════════╝\n\n";

            std::cout << "1. Explore Clubs\n";
            std::cout << "2. View Events\n";
            std::cout << "3. My Joined Clubs\n";
            std::cout << "4. Exit\n\n";

            std::cout << "Enter your choice (1-4): ";
            while (!(std::cin >> choice) || choice < 1 || choice > 4) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number between 1 and 4: ";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            switch (choice) {
            case 1:
                exploreClubs();
                break;
            case 2:
                viewEvents();
                break;
            case 3:
                myJoinedClubs();
                break;
            case 4:
                exitProgram();
                running = false;
                break;
            }
        }
    }

    void exploreClubs() {
        clearScreen();
        displayHeader();

        std::cout << "╔═══════════════════════════════╗\n";
        std::cout << "║         EXPLORE CLUBS         ║\n";
        std::cout << "╚═══════════════════════════════╝\n\n";

        if (allClubs.empty()) {
            std::cout << "No clubs available at the moment.\n";
            waitForEnter();
            return;
        }

        for (size_t i = 0; i < allClubs.size(); i++) {
            std::cout << i + 1 << ". " << allClubs[i].getName() << "\n";
            std::cout << "   " << allClubs[i].getDescription() << "\n";

            if (isClubJoined(allClubs[i].getName())) {
                std::cout << "   [Already Joined]\n";
            }

            std::cout << "\n";
        }

        std::cout << "0. Back to Main Menu\n\n";
        std::cout << "Enter club number to join (or 0 to go back): ";

        int choice;
        while (!(std::cin >> choice) || choice < 0 || choice > static_cast<int>(allClubs.size())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid club number: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) {
            return;
        }

        const Club& selectedClub = allClubs[choice - 1];

        if (isClubJoined(selectedClub.getName())) {
            std::cout << "\nYou have already joined " << selectedClub.getName() << "!\n";
        } else {
            joinedClubs.push_back(selectedClub);
            std::cout << "\nYou have successfully joined " << selectedClub.getName() << "!\n";
            saveJoinedClubs();
        }

        waitForEnter();
    }

    void viewEvents() {
        clearScreen();
        displayHeader();

        std::cout << "╔═══════════════════════════════╗\n";
        std::cout << "║          VIEW EVENTS          ║\n";
        std::cout << "╚═══════════════════════════════╝\n\n";

        if (allEvents.empty()) {
            std::cout << "No events available at the moment.\n";
            waitForEnter();
            return;
        }

        std::cout << "Filter events by club:\n";
        std::cout << "0. All Events\n";

        std::vector<std::string> uniqueClubs;
        for (const auto& event : allEvents) {
            if (std::find(uniqueClubs.begin(), uniqueClubs.end(), event.getClubName()) == uniqueClubs.end()) {
                uniqueClubs.push_back(event.getClubName());
            }
        }

        for (size_t i = 0; i < uniqueClubs.size(); i++) {
            std::cout << i + 1 << ". " << uniqueClubs[i] << "\n";
        }

        std::cout << "\nEnter your choice (0-" << uniqueClubs.size() << "): ";

        int filterChoice;
        while (!(std::cin >> filterChoice) || filterChoice < 0 || filterChoice > static_cast<int>(uniqueClubs.size())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid number: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        clearScreen();
        displayHeader();

        std::cout << "╔═══════════════════════════════╗\n";
        std::cout << "║          EVENT LIST           ║\n";
        std::cout << "╚═══════════════════════════════╝\n\n";

        std::string filterClub = (filterChoice == 0) ? "" : uniqueClubs[filterChoice - 1];

        bool eventsFound = false;
        for (const auto& event : allEvents) {
            if (filterClub.empty() || event.getClubName() == filterClub) {
                eventsFound = true;
                std::cout << "Event: " << event.getName() << "\n";
                std::cout << "Date: " << event.getDate() << "\n";
                std::cout << "Club: " << event.getClubName() << "\n";
                std::cout << "Description: " << event.getDescription() << "\n\n";
            }
        }

        if (!eventsFound) {
            std::cout << "No events found for the selected filter.\n";
        }

        waitForEnter();
    }

    void myJoinedClubs() {
        clearScreen();
        displayHeader();

        std::cout << "╔═══════════════════════════════╗\n";
        std::cout << "║        MY JOINED CLUBS        ║\n";
        std::cout << "╚═══════════════════════════════╝\n\n";

        if (joinedClubs.empty()) {
            std::cout << "You haven't joined any clubs yet.\n";
            waitForEnter();
            return;
        }

        for (size_t i = 0; i < joinedClubs.size(); i++) {
            std::cout << i + 1 << ". " << joinedClubs[i].getName() << "\n";
            std::cout << "   " << joinedClubs[i].getDescription() << "\n\n";
        }

        std::cout << "0. Back to Main Menu\n";
        std::cout << "Enter club number to leave (or 0 to go back): ";

        int choice;
        while (!(std::cin >> choice) || choice < 0 || choice > static_cast<int>(joinedClubs.size())) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid club number: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) {
            return;
        }

        std::string clubName = joinedClubs[choice - 1].getName();
        joinedClubs.erase(joinedClubs.begin() + choice - 1);

        std::cout << "\nYou have left " << clubName << ".\n";
        saveJoinedClubs();

        waitForEnter();
    }

    void exitProgram() {
        clearScreen();
        displayHeader();

        std::cout << "╔═══════════════════════════════════════════════════════════╗\n";
        std::cout << "║                      THANK YOU!                           ║\n";
        std::cout << "║         For using CampusConnect. See you soon!            ║\n";
        std::cout << "╚═══════════════════════════════════════════════════════════╝\n\n";

        std::cout << "Saving your joined clubs...\n";
        displayAnimation();
        std::cout << "Save complete! Goodbye!\n\n";

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
};

int main() {
    CampusConnect app;
    app.start();
    return 0;
}