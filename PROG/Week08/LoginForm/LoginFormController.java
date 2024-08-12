package PROG.Week08.LoginForm;

import javafx.application.*;
import javafx.event.*;
import javafx.fxml.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.text.*;

public class LoginFormController extends Application {
	@FXML
	private TextField usernameTf;
	@FXML
	private PasswordField passwordPf;
	@FXML
	private Text resultT;
	private LoginForm loginForm = new LoginForm("sam", "mypassword");

	public static void main(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage stage) throws Exception {
		FXMLLoader loader = new FXMLLoader(getClass().getResource("/PROG/Week08/LoginForm/loginform.fxml"));
		Parent root = loader.load();

		Scene scene = new Scene(root, 300, 250);

		stage.setTitle("Login");
		stage.setScene(scene);
		stage.show();
	}

	@FXML
	private void login(ActionEvent event) {
		String username = usernameTf.getText();
		String password = passwordPf.getText();

		try {
			loginForm.login(username, password);
			resultT.setText("Password correct!");
		} catch (Exception e) {
			resultT.setText(e.getMessage());
		}
	}
}
