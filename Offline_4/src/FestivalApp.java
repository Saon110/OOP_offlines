import java.util.Scanner;


/* This is the driver class for this project. You need to run this class with three command line arguments corresponding to the name, starting date and maxinum number of allowed events of a festival. For exmaple run the below command from the termincal:
java FestivalApp "CSE Fest 2023" "2023-07-15" 10*/
public class FestivalApp {

    public static void main(String[] args) {
        // Task: The program will be run with three command line arguements related to a
        // festival- (i) the festival's name, (ii) its starting date and (iii) the
        // maximum number of events allowed in the festival. Create a FestivalManager
        // object named 'festivalManager' and initialize it with the values passed from
        // the command line as: FestivalManager festivalManager = new
        // FestivalManager(...); Generate error if the required parameters are not
        // passed from the command line.

        // Write your code here

        FestivalManager festivalManager = new FestivalManager(args[0], args[1], Integer.parseInt(args[2]));

        int choice;
        Scanner scanner = new Scanner(System.in);

        do {
            // the following lines of code show a menu to take user's choice

            System.out.println("Menu:");
            System.out.println("1. Add an event");
            System.out.println("2. Register student in an event");
            System.out.println("3. View festival details");
            System.out.println("4. View specific event");
            System.out.println("5. View Event on Date");
            System.out.println("6. View event with maximum participants");
            System.out.println("7. View events for students");
            System.out.println("8. Cancel registration");
            System.out.println("9. Exit");
            System.out.print("Enter option:");

            choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1: // Add an event
                    /*
                     * Task: using the scanner object, read the following information for an event:
                     * (i) name as a string, (ii) starting date as a string in 'YYYY-MM-DD' format,
                     * (iii) location as a string, and (iv) max number of participants allowed in
                     * the
                     * event as an integer. Invoke the function 'add event' of 'Festival Manager' to
                     * add the event, i.e., call festivalManager.addEvent(...)
                     */

                    // Write your code here
                    System.out.print("Enter event name:");
                    String e = scanner.nextLine();
                    System.out.print("Enter event date:");
                    String d = scanner.nextLine();
                    System.out.print("Enter event location:");
                    String l = scanner.nextLine();
                    System.out.print("Enter maximum participants:");
                    int max = scanner.nextInt();
                    Event event = new Event(e, d, l, max);
                    festivalManager.addEvent(event);
                    System.out.print("\nEvent added successfully!\n");

                    break;

                case 2:// Register a student in an event
                    /*
                     * Task: read the name and id of a student and an event name. Then register the
                     * student in the event by calling the function:
                     * festivalManager.registerStudent(...)
                     */

                    // Write your code here
                    System.out.print("Enter student name:");
                    String n = scanner.nextLine();
                    System.out.print("Enter student ID:");
                    String id = scanner.nextLine();
                    Student s = new Student(n, id);
                    System.out.print("Enter event name:");
                    String e1 = scanner.nextLine();
                    festivalManager.registerStudent(e1, s);

                    break;

                case 3: // View festival details

                    festivalManager.showDetails();

                    break;

                case 4: // View event details
                    /*
                     * Task: read the name of an event and then show the details for the event by
                     * calling the function: festivalManager.showEvent(...);
                     */

                    // Write your code here
                    System.out.print("Enter Event Name:");
                    String eventName = scanner.nextLine();
                    festivalManager.showEvent(eventName);

                    break;

                case 5: // View events on date

                    System.out.print("Enter event date:");
                    String d1 = scanner.nextLine();
                    System.out.println(("\nEvents on " + d1 + " are:"));
                    festivalManager.showEventsOnDate(d1);
                    break;

                case 6: // View event with maximum participants

                    System.out.println("\nEvent with highest participants:");
                    festivalManager.eventWithHighestParticipants();

                    break;

                case 7: // View events for students
                    /*
                     * Task: read the id of a student and then show the events the student is
                     * participating in by calling the function:
                     * festivalManager.showEventsForStudent(...);
                     */

                    // Write your code here

                    System.out.print("Enter Student ID:");

                    String studentId = scanner.nextLine();
                    System.out.println("\nStudent " + studentId + " is registered in:");
                    festivalManager.showEventsForStudent(studentId);

                    break;

                case 8: // Cancel registration
                    /*
                     * Task: read the id of a student and an event name. Then remove the student
                     * from the participant list of the event by calling the function:
                     * festivalManager.cancelRegistration(...);
                     */

                    // Write your code here
                    System.out.print("Enter Student ID:");
                    String id1 = scanner.nextLine();
                    System.out.print("Enter event name:");
                    String n1 = scanner.nextLine();
                    festivalManager.cancelRegistration(n1, id1);

                    break;

                case 9:
                    System.out.println("Exiting the program.");
                    break;

                default:
                    System.out.println("Invalid option. Please try again.");
            }
            System.out.println();
        } while (choice != 9);

        scanner.close();
    }
}
