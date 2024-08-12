package PROG.Week08.Calculator;

import PROG.Week08.Calculator.Calculator.Operations;
import javafx.application.*;
import javafx.event.*;
import javafx.fxml.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.control.*;

public class CalculatorController extends Application {
    @FXML
    private TextField firstNumberTf;
    @FXML
    private TextField secondNumberTf;
    @FXML
    private TextField resultTf;
    private Calculator calculator = new Calculator();

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage stage) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/PROG/Week08/Calculator/calculator.fxml"));
        Parent root = loader.load();

        Scene scene = new Scene(root, 300, 250);

        stage.setTitle("Calculator");
        stage.setScene(scene);
        stage.show();
    }

    @FXML
    private void calculateResult(ActionEvent event) {
        Double firstNumber = this.parseDouble(firstNumberTf.getText());
        Double secondNumber = this.parseDouble(secondNumberTf.getText());

        if (firstNumber == null) {
            resultTf.setText("Missing first number.");
            return;
        }
        if (secondNumber == null) {
            resultTf.setText("Missing second number.");
            return;
        }
        if (calculator.getOperation() == null) {
            resultTf.setText("Missing operation.");
            return;
        }

        try {
            calculator.setFirstNumber(firstNumber);
            calculator.setSecondNumber(secondNumber);
            resultTf.setText(String.valueOf(calculator.getResult()));
        } catch (Exception e) {
            resultTf.setText(e.getMessage());
        }
    }

    private Double parseDouble(String text) {
        try {
            return Double.parseDouble(text);
        } catch (NumberFormatException e) {
            return null;
        }
    }

    @FXML
    private void setAdd(ActionEvent event) {
        calculator.setOperation(Operations.ADD);
    }

    @FXML
    private void setSubtract(ActionEvent event) {
        calculator.setOperation(Operations.SUBTRACT);
    }

    @FXML
    private void setMultiply(ActionEvent event) {
        calculator.setOperation(Operations.MULTIPLY);
    }

    @FXML
    private void setDivide(ActionEvent event) {
        calculator.setOperation(Operations.DIVIDE);
    }
}
