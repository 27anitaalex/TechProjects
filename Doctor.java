// Doctor.java
// Anita Alex

public class Doctor {
    // represents a doctor and stores their name and specialty

    private String name; // stores doctor's name
    private String specialty; // stores doctor's specialty

    public Doctor(String name, String specialty) {
        // constructor and runs when a new doctor object is created
        this.name = name; // parameter gets assigned to the instance variable
        this.specialty = specialty;
    }

    // returns doctor's name
    public String getName() {
        return name;
    }

    // returns doctor's specialty
    public String getSpecialty() {
        return specialty;
    }

    @Override // this method replaces the default toString() method
    public String toString() {
        return name + " (" + specialty + ")"; // returns formatted info about the doctor
    }
}