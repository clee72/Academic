/**
Workshop 5
Section: NEE
Name: Wonhwa Lee
Student No.: 076 086 149
Email: wlee72@myseneca.ca
*/

package application;

import java.util.ArrayList;
import java.util.Optional;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonBar.ButtonData;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Main extends Application {

	// Labels
	private Label lbStu = new Label("Student ID: ");
	private Label lbFname = new Label("First Name: ");
	private Label lbLname = new Label("Last Name: ");
	private Label lbCourse = new Label("Course: ");
	private Label lbDisplay = new Label("Enrollment Details: ");

	// Dialogs
	private Alert alert = new Alert(AlertType.WARNING);
	private Alert result = new Alert(AlertType.INFORMATION);
	private Alert confirm = new Alert(AlertType.CONFIRMATION);

	// TextFields
	private TextField txtStu = new TextField();
	private TextField txtFname = new TextField();
	private TextField txtLname = new TextField();
	private TextField txtCourse = new TextField();

	// Buttons
	private Button btStu = new Button("Enter");
	private Button btFname = new Button("Enter");
	private Button btLname = new Button("Enter");
	private Button btAddCourse = new Button("Enter");
	private Button btAddNew = new Button("+Add");
	private Button btSubmit = new Button("Submit Registration");
	private Button btClear = new Button("Clear");
	private Button btView = new Button("View Results");

	// TextArea
	private TextArea textArea = new TextArea();

	// Temporary Storage for courses
	ArrayList<String> storage = new ArrayList<String>();

	public static void main(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage stage) throws Exception {

		Student student = new Student();

		WriteFile wf = new WriteFile();
		ReadFile rf = new ReadFile();

		/** Layout : Stage > Scene > Pane, Control > Nodes */

		GridPane pane = new GridPane();

		pane.setHgap(5);
		pane.setVgap(5);

		pane.add(lbStu, 0, 0);
		pane.add(txtStu, 1, 0);
		pane.add(btStu, 2, 0);

		pane.add(lbFname, 0, 1);
		pane.add(txtFname, 1, 1);
		pane.add(btFname, 2, 1);

		pane.add(lbLname, 0, 2);
		pane.add(txtLname, 1, 2);
		pane.add(btLname, 2, 2);

		pane.add(lbCourse, 0, 3);
		pane.add(txtCourse, 1, 3);
		pane.add(btAddCourse, 2, 3);
		pane.add(btAddNew, 3, 3);

		pane.add(btSubmit, 1, 5);
		pane.add(btClear, 2, 5);

		pane.add(lbDisplay, 0, 7);
		pane.add(btView, 1, 7);

		
		/** Event Handling: When button was clicked.. */

		// Student ID
		btStu.setOnAction(e -> {

			try {
				if (txtStu.getText().isEmpty()) {
					alert.setTitle("Error");
					alert.setHeaderText("Invalid");
					alert.setContentText("It shouldn't be blank, Please enter the valid number!");
					alert.showAndWait();

				} else {
					student.setStdID(Integer.parseInt(txtStu.getText()));

					// Change button color to green, when valid input is entered
					btStu.setText("Entered");
					btStu.setStyle("-fx-background-color: lightGreen");
				}
			} catch (NumberFormatException e1) {
				alert.setTitle("Error");
				alert.setHeaderText(e1.getMessage());
				alert.setContentText("Please enter the valid nubmer!");
				alert.showAndWait();

				// Reset button color when the input is invalid
				btStu.setText("Enter");
				btStu.setStyle("-fx-background: #f4f4f4");

			} catch (Exception e1) {
				alert.setTitle("Error");
				alert.setHeaderText(e1.getMessage());
				alert.setContentText("Please enter the valid number!");
				alert.showAndWait();

				// Reset button color when the input is invalid
				btStu.setText("Enter");
				btStu.setStyle("-fx-background: #f4f4f4");
			}
		});

		// First Name
		btFname.setOnAction(e -> {
			try {
				student.setFirstName(txtFname.getText());

				// Change button color to green, when valid input is entered
				btFname.setText("Entered");
				btFname.setStyle("-fx-background-color: lightGreen");

			} catch (Exception e1) {
				alert.setTitle("Error");
				alert.setHeaderText(e1.getMessage());
				alert.setContentText("Please enter first name!");
				alert.showAndWait();
			}
		});

		// Last Name
		btLname.setOnAction(e -> {
			try {
				student.setLastName(txtLname.getText());

				// Change button color to green, when valid input is entered
				btLname.setText("Entered");
				btLname.setStyle("-fx-background-color: lightGreen");
			} catch (Exception e1) {
				alert.setTitle("Error");
				alert.setHeaderText(e1.getMessage());
				alert.setContentText("Please enter last name!");
				alert.showAndWait();
			}
		});

		// Course
		btAddCourse.setOnAction(e -> {

			if (txtCourse.getText().isEmpty()) {
				alert.setTitle("Error");
				alert.setContentText("Please enter course!");
				alert.showAndWait();
			} else {
				storage.add(txtCourse.getText());

				// Change button color to green, when valid input is entered
				btAddCourse.setText("Entered");
				btAddCourse.setStyle("-fx-background-color: lightGreen");
			}
		});

		// Add New Course
		btAddNew.setOnAction(e -> {
			btAddCourse.setText("Enter");

			// Reset button color, when "Add" button is clicked
			btAddCourse.setStyle("-fx-background: #f4f4f4");
			txtCourse.clear();
		});

		// Submit enrollment form
		btSubmit.setOnAction(e -> {
			try {
				for (int i = 0; i < storage.size(); i++) {
					student.setCourses(storage.get(i));
				}

			} catch (Exception e1) {
				alert.setTitle("Error");
				alert.setHeaderText(e1.getMessage());
				alert.setContentText("Please enter course!");
				alert.showAndWait();
			}

			// Write file
			wf.writeFile(student, WriteFile.FILENAME);
			result.setTitle("Result");
			result.setContentText("Submitted!");
			result.showAndWait();
		});

		// Clear form
		btClear.setOnAction(e -> {

			confirm.setTitle("Are you sure you want to clear this form?");

			ButtonType yes = new ButtonType("Yes");
			ButtonType no = new ButtonType("No", ButtonData.CANCEL_CLOSE);

			confirm.getButtonTypes().setAll(yes, no);

			Optional<ButtonType> answer = confirm.showAndWait();

			if (answer.get() == yes) {
				txtStu.clear();
				txtFname.clear();
				txtLname.clear();
				txtCourse.clear();
				textArea.clear();

				btStu.setText("Enter");
				btStu.setStyle("-fx-background: #f4f4f4");

				btFname.setText("Enter");
				btFname.setStyle("-fx-background: #f4f4f4");

				btLname.setText("Enter");
				btLname.setStyle("-fx-background: #f4f4f4");

				btAddCourse.setText("Enter");
				btAddCourse.setStyle("-fx-background: #f4f4f4");

			}
		});

		// View enrollment result
		btView.setOnAction(e -> {

			textArea.clear();
			// Read file
			Student clone = rf.readFile(WriteFile.FILENAME);
			String id = Integer.toString(clone.getStdID());

			textArea.setText("[Student ID]:  " + id);
			textArea.appendText("\n");

			textArea.appendText("[First Name]:  " + clone.getFirstName());
			textArea.appendText("\n");

			textArea.appendText("[Last Name]:  " + clone.getLastName());
			textArea.appendText("\n");

			textArea.appendText("[Course Lists]:  " + clone.getCourses());

			textArea.setStyle("-fx-highlight-fill: #ADFF2F; -fx-highlight-text-fill: #B22222; -fx-font-size: 16px;");
		});

		VBox vb = new VBox(pane, textArea);

		vb.setPadding(new Insets(10, 50, 50, 50));
		vb.setSpacing(10);

		Scene scene = new Scene(vb, 720, 420);

		stage.setTitle("Class Registration");
		stage.setScene(scene);
		stage.show();
	}

}
