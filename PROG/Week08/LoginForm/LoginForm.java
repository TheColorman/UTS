package PROG.Week08.LoginForm;

public class LoginForm {
    String username;
    String password;

    public LoginForm(String username, String password) {
        this.username = username;
        this.password = password;
    }

    public void login(String username, String password) throws Exception {
        if (this.username.equals(username) && this.password.equals(password))
            return;

        throw new Exception("Password incorrect!");
    }
}
