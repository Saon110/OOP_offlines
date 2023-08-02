/* This class stores information of a festival which are name, starting date and list of events that will take place during the festival. */

public class FestivalManager {

    private String name;
    private String startDate;
    private Event[] events;
    int eventsAdded = 0;
    int maxEventCount;

    // Task: Write code for the constructor below to initialize the member variables
    // properly

    public FestivalManager(String name, String startDate, int maxEventCount) {

        // write your code here

        this.name = name;
        this.startDate = startDate;
        this.events = new Event[maxEventCount];
        this.maxEventCount = maxEventCount;

    }

    // Task: Write code for the function below. This function adds an event to this
    // festival. Check for the following case: (i) total event count does not exceed
    // the maximum number of events allowed for this festival

    public void addEvent(Event e) {
        // write your code here
        if (eventsAdded == events.length) {
            System.out.println("Maximum events reached!!!");

        }

        else {
            events[eventsAdded] = e;
            eventsAdded++;
        }

    }

    // Task: Write code for the function below. This function registers a student
    // for an event in this festival. Check for the following case: (i) event does
    // not exist
    public void registerStudent(String eventName, Student s) {
        // Write your code here

        int k = 0;

        for (int i = 0; i < eventsAdded; i++) {

            if (events[i].getEventName().equals(eventName)) {

                events[i].addParticipant(s);
                break;

            }
            k++;
        }

        if (k == eventsAdded) {
            System.out.println("Event does not exist.");
        }
    }

    // Task: Write code for the function below. The function shows the details of
    // this festival. Make sure the output matches with the supplied sample output.
    public void showDetails() {
        // Write your code here

        System.out.println("Festival Name: " + this.name);
        System.out.println("Start Date: " + this.startDate);
        System.out.println("Festival Events:");
        for (int i = 0; i < eventsAdded; i++) {
            events[i].showDetails();
        }

    }

    // Task: Write code for the function below. This function shows details of the
    // event in the argument. Check for the following case: (i) event does not exist
    public void showEvent(String eventName) {
        // Write your code here
        int k = 0;
        for (int i = 0; i < eventsAdded; i++) {

            if (events[i].getEventName().equals(eventName)) {
                events[i].showDetails();
                break;
            }
            k++;
        }

        if (k == eventsAdded) {
            System.out.println("Event does not exist.");
        }
    }

    // Task: Write code for the function below. This function shows details of the
    // events that will start on the date passed as its argument. Check for the
    // following case: (i) event does not exist
    public void showEventsOnDate(String eventDate) {
        // Write your code here
        int k = 0;
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventDate().equals(eventDate)) {

                System.out.println(events[i].getEventName());
            } else
                k++;
        }
        if (k == eventsAdded) {
            System.out.println("None");
        }
    }

    // Task: Write code for the function below. This function shows the details of
    // the events with maximum number of participants. If there are multiple events,
    // show all.
    public void eventWithHighestParticipants() {
        // Write your code here
        int max = -1;
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getParticipantsAdded() > max) {
                max = events[i].getParticipantsAdded();
            }
        }
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getParticipantsAdded() == max) {
                events[i].showDetails();

            }
        }
    }

    // Task: Write code for the function below. This function takes a student Id as
    // input and then lists all the events this particular student has registered
    // for. Make sure your output matches the supplied sample output.
    public void showEventsForStudent(String studentId) {
        // Write your code here
        for (int i = 0; i < eventsAdded; i++) {
            for (int j = 0; j < events[i].getParticipantsAdded(); j++) {
                if (events[i].getRegisteredStudents()[j].getId().equals(studentId)) {

                    // events[i].showDetails();
                    System.out.println(events[i].getEventName());
                }
            }
        }
    }

    // Task: Write code for the function below. This functions takes an event's name
    // and a student's ID as arguments and then removes the student from the
    // registered student list of the event. Check for the following cases: (i)
    // event does not exist, (ii) student is not registered for the event
    public void cancelRegistration(String eventName, String studentId) {
        // Write your code here
        int k = 0;
        for (int i = 0; i < eventsAdded; i++) {
            if (events[i].getEventName().equals(eventName)) {
                
                events[i].removeParticipant(studentId);
                
                break;
            }
            k++;
        }

        if (k == eventsAdded) {
            System.out.println("\nEvent does not exist.");
        }

    }

    // public static void main(String[] args) {
    //     // Event[] e1 = new Event[2];
    //     Student s1;
    //     s1 = new Student("Saon", "2105110");
    //     s1.showDetails();
    //     Student[] s = new Student[3];
    //     s[0] = s1;
    //     s[1] = new Student("Afham", "2105119");
    //     s[2] = new Student("Avee", "2105112");

    //     Event e;
    //     e = new Event("Jam", "2023-07-23", "ECE", 10);
    //     e.addParticipant(s1);
    //     e.addParticipant(s[1]);
    //     e.addParticipant(s[2]);
    //     e.showDetails();
    //     e.removeParticipant("2105119");
    //     e.showDetails();
    //     // if (e.isRegistered("2105106")) {
    //     // System.out.println("Registered:)");
    //     // } else
    //     // System.out.println("NOOOOO:(");
    //     FestivalManager festm;
    //     festm = new FestivalManager("CFEST", "2023-07-23", 10);
    //     // festm.addEvent(e);
    //     Event e1;
    //     e1 = new Event("PC", "2023-07-23", "ECE", 30);
    //     e1.addParticipant(s1);
    //     e1.addParticipant(s[1]);
    //     // e1.showDetails();
    //     festm.addEvent(e);
    //     festm.addEvent(e1);
    //     festm.showDetails();
    //     System.out.println("register new student");
    //     festm.registerStudent("Jam", s[1]);
    //     festm.showDetails();
    //     festm.showEvent("PC");
    //     System.out.println("\nShowing events on date 2023-07-23");
    //     festm.showEventsOnDate("2023-07-23");
    //     System.out.println("\nShowing events with highest participants"); // e
    //     festm.eventWithHighestParticipants();
    //     festm.showEventsForStudent("2105119");
    //     festm.cancelRegistration("Jam", "2105110");
    //     festm.showDetails();
    //     festm.cancelRegistration("Jam", "2105111");
    // }
}
