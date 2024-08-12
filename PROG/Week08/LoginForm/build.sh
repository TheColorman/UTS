rm -rf bin
mkdir bin
javac -sourcepath ../../.. -d bin LoginFormController.java LoginForm.java
cp loginform.fxml bin/PROG/Week08/LoginForm/
jar cfe LoginForm.jar PROG.Week08.LoginForm.LoginFormController -C bin/ .
mv LoginForm.jar bin/