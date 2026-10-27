// Patient.java
// Anita Alex

public class Patient {
    // represents a patient
    // stores information about patient's name and age

    private String name; // stores the patient's name
    private int age; // stores patient's age

    public Patient(String name, int age) { // constructor runs when new Patient object is created
        this.name = name; // parameter gets assigned to the instance variable
        this.age = age; // parameter gets assigned to the instance variable
    }

    // returns patients name
    public String getName() {
        return name;
    }

    // returns patients age
    public int getAge() {
        return age;
    }
}