// MedicalScheduler.java
// Anita Alex

import javax.swing.*; // imports all swing classes used to create GUI components
import java.awt.*; // imports all layout managers and graphical features
import java.awt.event.*; // imports all event-handling classes
import java.util.ArrayList; // imports ArrayList that stores all appointments

public class MedicalScheduler extends JFrame { 
    // class that inherits features from JFrame which allows the class to create a GUI window

    private JTextField nameField; // textboxes for patient name
    private JTextField ageField; // textbox for age input
    private JTextField dateField; // textboc for appointment date input

    private JComboBox<Doctor> doctorBox; // dropdown menu containing the doctor objects

    private JButton scheduleButton; // creates a button for new appointment
    private JButton searchButton; // creates a button to search appointment
    private JButton cancelButton; // creates a button to cancel appointment

    private JTextArea appointmentArea; // a large text area that displays appointment history

    private ArrayList<Appointment> appointments; // stores all appointment objects

    public MedicalScheduler() { // constructor

        setTitle("Medical Appointment Scheduler"); // sets title bar
        setSize(600,500); // sets the window size
        setDefaultCloseOperation(EXIT_ON_CLOSE); // closes the program when the user clicks the X button
        setLocationRelativeTo(null); // window is in the center

        appointments = new ArrayList<>(); // creates an empty list that stores appointments
        nameField = new JTextField(); // creates textbox name
        ageField = new JTextField(); // creates textbox age
        dateField = new JTextField(); // creates textbox date 
        doctorBox = new JComboBox<>(); // creates an empty dropdown menu
        doctorBox.addItem(new Doctor( "Dr. Smith","Pediatrics")); // creates doctor object and adds to dropdown
        doctorBox.addItem(new Doctor("Dr. Johnson", "Cardiology"));
        doctorBox.addItem(new Doctor("Dr. Lee","Dermatology"));
        scheduleButton = new JButton("Schedule"); // creates schedule button
        searchButton = new JButton("Search"); // creates search button
        cancelButton = new JButton("Cancel Appointment"); // creates cancel appointment button
        appointmentArea = new JTextArea(15,40); // creates a text area 15 x 40
        appointmentArea.setEditable(false); // prevents user typing into the text area
        
        JPanel inputPanel = new JPanel(); // creates a panel to organize components
        inputPanel.setLayout(new GridLayout(5,2)); // creates a grid 5 x 2 filled with patients name, age, doctor, and date
        inputPanel.add(new JLabel("Patient Name:")); // creates and adds a label
        inputPanel.add(nameField); // adds the text field beside the label
        inputPanel.add(new JLabel("Age:"));
        inputPanel.add(ageField);
        inputPanel.add(new JLabel("Doctor:"));
        inputPanel.add(doctorBox);
        inputPanel.add(new JLabel("Appointment Date:"));
        inputPanel.add(dateField);
        inputPanel.add(scheduleButton); // adds a schedule button

        inputPanel.add(searchButton); // adds a search button

        add(
                inputPanel,
                BorderLayout.NORTH);
                // places the panel at the top
        add(
                new JScrollPane(
                        appointmentArea),
                BorderLayout.CENTER);
                // adds the appointment area in the center
                // JScrollPanel adds scroll bars if long list
        add(
                cancelButton,
                BorderLayout.SOUTH);
                // places cancel button at the bottom

        scheduleButton.addActionListener(
                new ActionListener() {
                // adds an event listener

                    @Override

                    public void actionPerformed(
                            ActionEvent e) {

                        scheduleAppointment();
                    }
                    // when clicked schedule appointment is called
                });

        searchButton.addActionListener(
                new ActionListener() {
                // adds an event listener

                    @Override

                    public void actionPerformed(
                            ActionEvent e) {

                        searchAppointments();
                    }
                    // when clicked searchAppointments is called
                });

        cancelButton.addActionListener(
                new ActionListener() {

                    @Override

                    public void actionPerformed(
                            ActionEvent e) {

                        cancelAppointment();
                    }
                    // when clicked cancelAppointment is called
                });

        setVisible(true); // makes GUI apear on the screen
    }

    private void scheduleAppointment() { // method schedules a new appointment

        try { // try block can help with errors 

            String name = nameField.getText(); // gets text from the patient name field

            int age = Integer.parseInt(ageField.getText()); // gets age from text field and converts it to an integer
            String date = dateField.getText(); // gets appointment date
            Doctor doctor = (Doctor)doctorBox.getSelectedItem(); // gets doctor selected from the dropdown menu

            if(name.isEmpty()|| date.isEmpty()) { // check if the name or date field is empty
            // if true then return please fill all fields
                JOptionPane.showMessageDialog(
                        this,
                        "Please fill all fields.");
                return;
            }

            Patient patient = new Patient(name,age); // creates a new patient object
            Appointment appointment = new Appointment(patient,doctor, date); // creates an appointment object
            appointments.add(appointment); // adds the appointment to the list
            appointmentArea.append(appointment + "\n"); // adds the appointment to the text area
            
            JOptionPane.showMessageDialog(
                    this,
                    "Appointment Scheduled!");
                    // this confirms that the appointment has been saved

            // clears input boxes
            nameField.setText("");
            ageField.setText("");
            dateField.setText("");
        }

        catch(NumberFormatException e) { // makes sure errors don't occur when code converts from string to a number
        // text isn't valid number

            JOptionPane.showMessageDialog(
                    this,
                    "Age must be a number.");
        }
    }

    private void searchAppointments() { // searches for appointments by patient name

        String searchName =
                JOptionPane.showInputDialog(
                        this,
                        "Enter patient name:");
                        // display a popup input box asking the user for a patient's name

        if(searchName == null)
            return;
            // if user pressed cancel

        String result = ""; // creates an empty string to store search results

        for(Appointment a : appointments) { // loops every appoitnment in the appointments ArrayList
            if(a.getPatient().getName().equalsIgnoreCase(searchName)) { // checks whether the patient's name matches the search
                result += a + "\n"; // adds appointment to result string
            }
        }
        
        // if string is empty, then no matching appointments were found
        if(result.isEmpty()) {
            result = "No appointments found.";
        }

        // displays the search results in a popup window
        JOptionPane.showMessageDialog(
                this,
                result);
    }

    private void cancelAppointment() { // when user clicks the cancel appointment

        String name =
                JOptionPane.showInputDialog(
                        this,
                        "Enter patient name:");
                        // displays an input box asking for a patient's name

        if(name == null)
            return;
            // if the user clicked cancel instead of typing a name

        boolean found = false; // creates a boolean if no appointment has been found yet

        for(Appointment a : appointments) { // loops through every appointment in the appointments ArrayList
            if(a.getPatient().getName().equalsIgnoreCase(name)&& !a.isCancelled()) {
               // checks whether the patient's name matches the name entered by the user
               // checks if appointment is not cancelled
                a.cancelAppointment(); // calls the method in appointment class
                found = true; // assigns found to true if matching appointment was found and cancelled
                JOptionPane.showMessageDialog(
                        this,
                        "Appointment Cancelled.");
                break; // stops loop immediately to stop checking the other appointments
                // shows a popup window that appointment is cancelled
            }
        }

        if(!found) { // if no appointment was found then display that appointment was not found
            JOptionPane.showMessageDialog(
                    this,
                    "Appointment not found.");
        }
    }

    // main method 
    public static void main(
            String[] args) {

        new MedicalScheduler(); // creates a new medicalscheduler object so constructor runs and GUI window appears
    }
}