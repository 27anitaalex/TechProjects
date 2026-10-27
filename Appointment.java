// Appointment.java
// Anita Alex

public class Appointment {
    // represents one appointment and connects patient, doctor and date

    private Patient patient; // stores the patient 
    private Doctor doctor; // stores doctor assigned to appointment
    private String date; // store the appointment date
    private boolean cancelled; // store whether the appoitnment has been cancelled

    public Appointment( 
            Patient patient,
            Doctor doctor,
            String date) {
            // constructor runs when a new appointment is created

        this.patient = patient; // stores patient object passed into constructor
        this.doctor = doctor; // stores selected order 
        this.date = date; // stores the appointment date

        cancelled = false; // when appointment is first created it is not cancelled
    }
    
    // returns patient object
    public Patient getPatient() {
        return patient;
    }

    //returns doctor object
    public Doctor getDoctor() {
        return doctor;
    }

    // returns appointment date
    public String getDate() {
        return date;
    }

    //checks whether the appointment has been cancelled
    public boolean isCancelled() {
        return cancelled;
    }

    // changes appointment states to cancelled
    public void cancelAppointment() {
        cancelled = true;
    }

    @Override // overrides the toString() method default
    public String toString() {

        return patient.getName()
                + " | "
                + doctor.getName()
                + " | "
                + date
                + (cancelled ? " (Cancelled)" : "");
                
                // returns a formatted information of patient name, doctor, date, and whether it is cancelled or not
    }
}