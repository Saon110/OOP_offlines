/* This class stores the following information about an event: name, starting date, location and list of students registered for the event. */

public class Event {
    private String eventName;
    private String eventDate; // store in the format YYYY-MM-DD
    private String eventLocation;
    private Student[] registeredStudents;
    int participantsAdded = 0; // variable to keep track of number of participants so far added
    int maximumParticipants;

    // Task: Write code for the constructor below to initialize the member variables
    // properly

    public Event(String eventName, String eventDate, String eventLocation, int maximumParticipants) {
        // write your code here
        this.eventName = eventName;
        this.eventDate = eventDate;
        this.eventLocation = eventLocation;
        this.registeredStudents = new Student[maximumParticipants];
        this.maximumParticipants = maximumParticipants;

    }

    // Task: Write getters and setters for Event attributes as required

    public void setEventName(String eventName) {
        this.eventName = eventName;
    }

    public void setEventDate(String eventDate) {
        this.eventDate = eventDate;
    }

    public void setEventLocation(String eventLocation) {
        this.eventLocation = eventLocation;
    }

    public void setRegisteredStudents(Student[] registeredStudents) {
        this.registeredStudents = registeredStudents;
    }

    public String getEventName() {
        return this.eventName;
    }

    public String getEventDate() {
        return this.eventDate;
    }

    public String getEventLocation() {
        return this.eventLocation;
    }

    public Student[] getRegisteredStudents() {
        return this.registeredStudents;
    }

    public int getParticipantsAdded() {
        return this.participantsAdded;
    }

    // Task: Write your code for the function below. This functions adds a
    // participant to this event. Check for the following cases: (i) total
    // participant count does not exceed the maximum participant count, (ii) the
    // studentId is not already added.
    public void addParticipant(Student student) {
        // write your code here
        if (participantsAdded == maximumParticipants) {
            System.out.println("Maximum participation reached.");
            return;
        }
        int i = 0;
        for (int j = 0; j < participantsAdded; j++) {
            if (student.getId().equals(registeredStudents[j].getId())) {
                i = 1;
            }
        }
        if (i == 1) {
            System.out.println("Student already added.");
            return;
        }

        registeredStudents[participantsAdded] = student;
        participantsAdded++;
        System.out.println("\nStudent registration complete.");

    }

    // Task: Write code for the function below. This function shows the details of
    // an event. Make sure your output matches with the supplied sample output.
    public void showDetails() {
        // Write your code here

        System.out.printf("Name:" + this.eventName + "\n");
        System.out.printf("Date:" + this.eventDate + "\n");
        System.out.printf("Location:" + this.eventLocation + "\n");
        System.out.printf("Registered Participants:\n");

        for (int i = 0; i < participantsAdded; i++) {

            registeredStudents[i].showDetails();

        }
        System.out.println();

    }

    // Task: Write code for the function below. This function check whether the
    // studentId in the argument has registered for this event or not. Return true
    // if registered, otherwise return false.
    public boolean isRegistered(String studentId) {
        // Write your code here
        for (int i = 0; i < participantsAdded; i++) {
            if (registeredStudents[i].getId() == studentId) {
                return true;
            }
        }
        return false;
    }

    // Task: Write code for the function below. This function removes a participant
    // from this event. Check for the following cases: (i) the student Id is not
    // regiseterd.
    public void removeParticipant(String studentId) {
        // Write your code here
        // int x = -1;
        int k = 0;
        for (int i = 0; i < participantsAdded; i++) {
            if (registeredStudents[i].getId().equals(studentId)) {
                // x=i;
                break;
            }
            k++;
        }

        if (k == participantsAdded) {
            System.out.println("\nStudent not registered.");
            return;
        }

        for (int j = k; j < participantsAdded-1; j++) {
            registeredStudents[j] = registeredStudents[j + 1];
        }
        participantsAdded--;
        System.out.println("\nSuccessfully removed id "+studentId+" from the event "+this.eventName);
    }

   

}