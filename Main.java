package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.ColumnConstraints;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import java.awt.*;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{


        GridPane roo=new GridPane();
        roo.setVgap(5);
        roo.setHgap(10);
        Label labl=new Label();
        labl.setText("Длина");
        roo.add(labl,1,1);
        Label labl1=new Label();
        labl1.setText("Высота");
        roo.add(labl1,1,2);
        Label labl2=new Label();
        roo.add(labl2,2,3);
        Label labl3=new Label();
        roo.add(labl3,4,3);
        TextField word=new TextField();
        roo.add(word,3,1);
        TextField word1=new TextField();
        roo.add(word1,3,2);
        Button bt=new Button();
        bt.setText("Площадь");
        bt.setMinWidth(100);
        bt.setMaxWidth(100);
        roo.getColumnConstraints().add(new ColumnConstraints(10,20,25));
        roo.getColumnConstraints().add(new ColumnConstraints(75,100,150));
        bt.setOnAction(event  ->
        {
           String a=word.getText();
            String c = word1.getText();
           if(isDouble(a)&& isDouble(c))
           {
               int b = Integer.parseInt(a);
               int g = Integer.parseInt(c);
               int x = b * g;
               labl2.setText(String.valueOf(x));
           }else
               {
                   labl2.setText("Error");
               }
        });
        Button bt1=new Button();
        bt1.setText("Периметр");
        bt1.setMinWidth(150);
        bt1.setMaxWidth(150);
        bt1.setOnAction(event  ->
        {
            String u=word.getText();
            String c = word1.getText();
            if(isDouble(u) && isDouble(c))
            {
                int b = Integer.parseInt(u);
                int g = Integer.parseInt(c);
                int k = b + g;
                labl3.setText(String.valueOf(k));
            }
            else
            {
                labl3.setText("Error");
            }
        });
        roo.add(bt,1,3);
        roo.add(bt1,3,3);
        primaryStage.setTitle("Hello World");
        primaryStage.setScene(new Scene(roo, 400, 375));
        primaryStage.show();
    }

    private boolean isDouble(String num){
        try {
            Double.parseDouble(num);
            return true;
        }catch(Exception e)
        {
            return false;
        }
    }
    public static void main(String[] args) {
        launch(args);
    }
}
