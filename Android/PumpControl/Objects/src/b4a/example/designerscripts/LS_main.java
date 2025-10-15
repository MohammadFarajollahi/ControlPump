package b4a.example.designerscripts;
import anywheresoftware.b4a.objects.TextViewWrapper;
import anywheresoftware.b4a.objects.ImageViewWrapper;
import anywheresoftware.b4a.BA;


public class LS_main{

public static void LS_320x480_1(anywheresoftware.b4a.BA ba, android.view.View parent, anywheresoftware.b4a.keywords.LayoutValues lv, java.util.Map props,
java.util.Map<String, anywheresoftware.b4a.keywords.LayoutBuilder.ViewWrapperAndAnchor> views, int width, int height, float scale) throws Exception {
anywheresoftware.b4a.keywords.LayoutBuilder.setScaleRate(0.3);
//BA.debugLineNum = 2;BA.debugLine="Button1.SetLeftAndRight(70%x,87%x)"[main/320x480,scale=1]
views.get("button1").vw.setLeft((int)((70d / 100 * width)));
views.get("button1").vw.setWidth((int)((87d / 100 * width) - ((70d / 100 * width))));
//BA.debugLineNum = 3;BA.debugLine="Button1.SetTopAndBottom(80%y,85%y)"[main/320x480,scale=1]
views.get("button1").vw.setTop((int)((80d / 100 * height)));
views.get("button1").vw.setHeight((int)((85d / 100 * height) - ((80d / 100 * height))));
//BA.debugLineNum = 5;BA.debugLine="lstDevices.SetLeftAndRight(30%x,99%x)"[main/320x480,scale=1]
views.get("lstdevices").vw.setLeft((int)((30d / 100 * width)));
views.get("lstdevices").vw.setWidth((int)((99d / 100 * width) - ((30d / 100 * width))));
//BA.debugLineNum = 6;BA.debugLine="lstDevices.SetTopAndBottom(1%y,20%y)"[main/320x480,scale=1]
views.get("lstdevices").vw.setTop((int)((1d / 100 * height)));
views.get("lstdevices").vw.setHeight((int)((20d / 100 * height) - ((1d / 100 * height))));
//BA.debugLineNum = 8;BA.debugLine="Label19.SetLeftAndRight(80%x,99%x)"[main/320x480,scale=1]
views.get("label19").vw.setLeft((int)((80d / 100 * width)));
views.get("label19").vw.setWidth((int)((99d / 100 * width) - ((80d / 100 * width))));
//BA.debugLineNum = 9;BA.debugLine="Label19.SetTopAndBottom(25%y,30%y)"[main/320x480,scale=1]
views.get("label19").vw.setTop((int)((25d / 100 * height)));
views.get("label19").vw.setHeight((int)((30d / 100 * height) - ((25d / 100 * height))));
//BA.debugLineNum = 10;BA.debugLine="Label20.SetLeftAndRight(65%x,80%x)"[main/320x480,scale=1]
views.get("label20").vw.setLeft((int)((65d / 100 * width)));
views.get("label20").vw.setWidth((int)((80d / 100 * width) - ((65d / 100 * width))));
//BA.debugLineNum = 11;BA.debugLine="Label20.SetTopAndBottom(25%y,30%y)"[main/320x480,scale=1]
views.get("label20").vw.setTop((int)((25d / 100 * height)));
views.get("label20").vw.setHeight((int)((30d / 100 * height) - ((25d / 100 * height))));
//BA.debugLineNum = 12;BA.debugLine="Label14.SetLeftAndRight(80%x,99%x)"[main/320x480,scale=1]
views.get("label14").vw.setLeft((int)((80d / 100 * width)));
views.get("label14").vw.setWidth((int)((99d / 100 * width) - ((80d / 100 * width))));
//BA.debugLineNum = 13;BA.debugLine="Label14.SetTopAndBottom(30%y,35%y)"[main/320x480,scale=1]
views.get("label14").vw.setTop((int)((30d / 100 * height)));
views.get("label14").vw.setHeight((int)((35d / 100 * height) - ((30d / 100 * height))));
//BA.debugLineNum = 14;BA.debugLine="Label16.SetLeftAndRight(65%x,80%x)"[main/320x480,scale=1]
views.get("label16").vw.setLeft((int)((65d / 100 * width)));
views.get("label16").vw.setWidth((int)((80d / 100 * width) - ((65d / 100 * width))));
//BA.debugLineNum = 15;BA.debugLine="Label16.SetTopAndBottom(30%y,35%y)"[main/320x480,scale=1]
views.get("label16").vw.setTop((int)((30d / 100 * height)));
views.get("label16").vw.setHeight((int)((35d / 100 * height) - ((30d / 100 * height))));
//BA.debugLineNum = 16;BA.debugLine="Label15.SetLeftAndRight(80%x,99%x)"[main/320x480,scale=1]
views.get("label15").vw.setLeft((int)((80d / 100 * width)));
views.get("label15").vw.setWidth((int)((99d / 100 * width) - ((80d / 100 * width))));
//BA.debugLineNum = 17;BA.debugLine="Label15.SetTopAndBottom(35%y,40%y)"[main/320x480,scale=1]
views.get("label15").vw.setTop((int)((35d / 100 * height)));
views.get("label15").vw.setHeight((int)((40d / 100 * height) - ((35d / 100 * height))));
//BA.debugLineNum = 18;BA.debugLine="Label17.SetLeftAndRight(65%x,80%x)"[main/320x480,scale=1]
views.get("label17").vw.setLeft((int)((65d / 100 * width)));
views.get("label17").vw.setWidth((int)((80d / 100 * width) - ((65d / 100 * width))));
//BA.debugLineNum = 19;BA.debugLine="Label17.SetTopAndBottom(35%y,40%y)"[main/320x480,scale=1]
views.get("label17").vw.setTop((int)((35d / 100 * height)));
views.get("label17").vw.setHeight((int)((40d / 100 * height) - ((35d / 100 * height))));
//BA.debugLineNum = 21;BA.debugLine="Label34.SetLeftAndRight(80%x,99%x)"[main/320x480,scale=1]
views.get("label34").vw.setLeft((int)((80d / 100 * width)));
views.get("label34").vw.setWidth((int)((99d / 100 * width) - ((80d / 100 * width))));
//BA.debugLineNum = 22;BA.debugLine="Label34.SetTopAndBottom(43%y,48%y)"[main/320x480,scale=1]
views.get("label34").vw.setTop((int)((43d / 100 * height)));
views.get("label34").vw.setHeight((int)((48d / 100 * height) - ((43d / 100 * height))));
//BA.debugLineNum = 23;BA.debugLine="Label35.SetLeftAndRight(70%x,99%x)"[main/320x480,scale=1]
views.get("label35").vw.setLeft((int)((70d / 100 * width)));
views.get("label35").vw.setWidth((int)((99d / 100 * width) - ((70d / 100 * width))));
//BA.debugLineNum = 24;BA.debugLine="Label35.SetTopAndBottom(48%y,53%y)"[main/320x480,scale=1]
views.get("label35").vw.setTop((int)((48d / 100 * height)));
views.get("label35").vw.setHeight((int)((53d / 100 * height) - ((48d / 100 * height))));
//BA.debugLineNum = 26;BA.debugLine="Button3.SetLeftAndRight(70%x,99%x)"[main/320x480,scale=1]
views.get("button3").vw.setLeft((int)((70d / 100 * width)));
views.get("button3").vw.setWidth((int)((99d / 100 * width) - ((70d / 100 * width))));
//BA.debugLineNum = 27;BA.debugLine="Button3.SetTopAndBottom(55%y,60%y)"[main/320x480,scale=1]
views.get("button3").vw.setTop((int)((55d / 100 * height)));
views.get("button3").vw.setHeight((int)((60d / 100 * height) - ((55d / 100 * height))));
//BA.debugLineNum = 29;BA.debugLine="btnSearch.SetLeftAndRight(1%x,28%x)"[main/320x480,scale=1]
views.get("btnsearch").vw.setLeft((int)((1d / 100 * width)));
views.get("btnsearch").vw.setWidth((int)((28d / 100 * width) - ((1d / 100 * width))));
//BA.debugLineNum = 30;BA.debugLine="btnSearch.SetTopAndBottom(1%y,7%y)"[main/320x480,scale=1]
views.get("btnsearch").vw.setTop((int)((1d / 100 * height)));
views.get("btnsearch").vw.setHeight((int)((7d / 100 * height) - ((1d / 100 * height))));
//BA.debugLineNum = 31;BA.debugLine="ImageView1.SetLeftAndRight(8%x,17%x)"[main/320x480,scale=1]
views.get("imageview1").vw.setLeft((int)((8d / 100 * width)));
views.get("imageview1").vw.setWidth((int)((17d / 100 * width) - ((8d / 100 * width))));
//BA.debugLineNum = 32;BA.debugLine="ImageView1.SetTopAndBottom(8%y,12%y)"[main/320x480,scale=1]
views.get("imageview1").vw.setTop((int)((8d / 100 * height)));
views.get("imageview1").vw.setHeight((int)((12d / 100 * height) - ((8d / 100 * height))));
//BA.debugLineNum = 33;BA.debugLine="Button2.SetLeftAndRight(1%x,28%x)"[main/320x480,scale=1]
views.get("button2").vw.setLeft((int)((1d / 100 * width)));
views.get("button2").vw.setWidth((int)((28d / 100 * width) - ((1d / 100 * width))));
//BA.debugLineNum = 34;BA.debugLine="Button2.SetTopAndBottom(13%y,20%y)"[main/320x480,scale=1]
views.get("button2").vw.setTop((int)((13d / 100 * height)));
views.get("button2").vw.setHeight((int)((20d / 100 * height) - ((13d / 100 * height))));
//BA.debugLineNum = 36;BA.debugLine="Label1.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label1").vw.setLeft((int)((5d / 100 * width)));
views.get("label1").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 37;BA.debugLine="Label1.SetTopAndBottom(20%y,25%y)"[main/320x480,scale=1]
views.get("label1").vw.setTop((int)((20d / 100 * height)));
views.get("label1").vw.setHeight((int)((25d / 100 * height) - ((20d / 100 * height))));
//BA.debugLineNum = 38;BA.debugLine="EditText1.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext1").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext1").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 39;BA.debugLine="EditText1.SetTopAndBottom(20%y,25%y)"[main/320x480,scale=1]
views.get("edittext1").vw.setTop((int)((20d / 100 * height)));
views.get("edittext1").vw.setHeight((int)((25d / 100 * height) - ((20d / 100 * height))));
//BA.debugLineNum = 41;BA.debugLine="Label2.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label2").vw.setLeft((int)((5d / 100 * width)));
views.get("label2").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 42;BA.debugLine="Label2.SetTopAndBottom(25%y,30%y)"[main/320x480,scale=1]
views.get("label2").vw.setTop((int)((25d / 100 * height)));
views.get("label2").vw.setHeight((int)((30d / 100 * height) - ((25d / 100 * height))));
//BA.debugLineNum = 43;BA.debugLine="EditText2.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext2").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext2").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 44;BA.debugLine="EditText2.SetTopAndBottom(25%y,30%y)"[main/320x480,scale=1]
views.get("edittext2").vw.setTop((int)((25d / 100 * height)));
views.get("edittext2").vw.setHeight((int)((30d / 100 * height) - ((25d / 100 * height))));
//BA.debugLineNum = 46;BA.debugLine="Label3.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label3").vw.setLeft((int)((5d / 100 * width)));
views.get("label3").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 47;BA.debugLine="Label3.SetTopAndBottom(30%y,35%y)"[main/320x480,scale=1]
views.get("label3").vw.setTop((int)((30d / 100 * height)));
views.get("label3").vw.setHeight((int)((35d / 100 * height) - ((30d / 100 * height))));
//BA.debugLineNum = 48;BA.debugLine="EditText3.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext3").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext3").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 49;BA.debugLine="EditText3.SetTopAndBottom(30%y,35%y)"[main/320x480,scale=1]
views.get("edittext3").vw.setTop((int)((30d / 100 * height)));
views.get("edittext3").vw.setHeight((int)((35d / 100 * height) - ((30d / 100 * height))));
//BA.debugLineNum = 51;BA.debugLine="Label4.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label4").vw.setLeft((int)((5d / 100 * width)));
views.get("label4").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 52;BA.debugLine="Label4.SetTopAndBottom(35%y,40%y)"[main/320x480,scale=1]
views.get("label4").vw.setTop((int)((35d / 100 * height)));
views.get("label4").vw.setHeight((int)((40d / 100 * height) - ((35d / 100 * height))));
//BA.debugLineNum = 53;BA.debugLine="EditText4.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext4").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext4").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 54;BA.debugLine="EditText4.SetTopAndBottom(35%y,40%y)"[main/320x480,scale=1]
views.get("edittext4").vw.setTop((int)((35d / 100 * height)));
views.get("edittext4").vw.setHeight((int)((40d / 100 * height) - ((35d / 100 * height))));
//BA.debugLineNum = 56;BA.debugLine="Label5.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label5").vw.setLeft((int)((5d / 100 * width)));
views.get("label5").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 57;BA.debugLine="Label5.SetTopAndBottom(40%y,45%y)"[main/320x480,scale=1]
views.get("label5").vw.setTop((int)((40d / 100 * height)));
views.get("label5").vw.setHeight((int)((45d / 100 * height) - ((40d / 100 * height))));
//BA.debugLineNum = 58;BA.debugLine="EditText5.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext5").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext5").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 59;BA.debugLine="EditText5.SetTopAndBottom(40%y,45%y)"[main/320x480,scale=1]
views.get("edittext5").vw.setTop((int)((40d / 100 * height)));
views.get("edittext5").vw.setHeight((int)((45d / 100 * height) - ((40d / 100 * height))));
//BA.debugLineNum = 61;BA.debugLine="Label6.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label6").vw.setLeft((int)((5d / 100 * width)));
views.get("label6").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 62;BA.debugLine="Label6.SetTopAndBottom(45%y,50%y)"[main/320x480,scale=1]
views.get("label6").vw.setTop((int)((45d / 100 * height)));
views.get("label6").vw.setHeight((int)((50d / 100 * height) - ((45d / 100 * height))));
//BA.debugLineNum = 63;BA.debugLine="EditText6.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext6").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext6").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 64;BA.debugLine="EditText6.SetTopAndBottom(45%y,50%y)"[main/320x480,scale=1]
views.get("edittext6").vw.setTop((int)((45d / 100 * height)));
views.get("edittext6").vw.setHeight((int)((50d / 100 * height) - ((45d / 100 * height))));
//BA.debugLineNum = 66;BA.debugLine="Label7.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label7").vw.setLeft((int)((5d / 100 * width)));
views.get("label7").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 67;BA.debugLine="Label7.SetTopAndBottom(50%y,55%y)"[main/320x480,scale=1]
views.get("label7").vw.setTop((int)((50d / 100 * height)));
views.get("label7").vw.setHeight((int)((55d / 100 * height) - ((50d / 100 * height))));
//BA.debugLineNum = 68;BA.debugLine="EditText7.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext7").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext7").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 69;BA.debugLine="EditText7.SetTopAndBottom(50%y,55%y)"[main/320x480,scale=1]
views.get("edittext7").vw.setTop((int)((50d / 100 * height)));
views.get("edittext7").vw.setHeight((int)((55d / 100 * height) - ((50d / 100 * height))));
//BA.debugLineNum = 71;BA.debugLine="Label8.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label8").vw.setLeft((int)((5d / 100 * width)));
views.get("label8").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 72;BA.debugLine="Label8.SetTopAndBottom(55%y,60%y)"[main/320x480,scale=1]
views.get("label8").vw.setTop((int)((55d / 100 * height)));
views.get("label8").vw.setHeight((int)((60d / 100 * height) - ((55d / 100 * height))));
//BA.debugLineNum = 73;BA.debugLine="EditText8.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext8").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext8").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 74;BA.debugLine="EditText8.SetTopAndBottom(55%y,60%y)"[main/320x480,scale=1]
views.get("edittext8").vw.setTop((int)((55d / 100 * height)));
views.get("edittext8").vw.setHeight((int)((60d / 100 * height) - ((55d / 100 * height))));
//BA.debugLineNum = 76;BA.debugLine="Label9.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label9").vw.setLeft((int)((5d / 100 * width)));
views.get("label9").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 77;BA.debugLine="Label9.SetTopAndBottom(60%y,65%y)"[main/320x480,scale=1]
views.get("label9").vw.setTop((int)((60d / 100 * height)));
views.get("label9").vw.setHeight((int)((65d / 100 * height) - ((60d / 100 * height))));
//BA.debugLineNum = 78;BA.debugLine="EditText9.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext9").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext9").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 79;BA.debugLine="EditText9.SetTopAndBottom(60%y,65%y)"[main/320x480,scale=1]
views.get("edittext9").vw.setTop((int)((60d / 100 * height)));
views.get("edittext9").vw.setHeight((int)((65d / 100 * height) - ((60d / 100 * height))));
//BA.debugLineNum = 81;BA.debugLine="Label10.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label10").vw.setLeft((int)((5d / 100 * width)));
views.get("label10").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 82;BA.debugLine="Label10.SetTopAndBottom(65%y,70%y)"[main/320x480,scale=1]
views.get("label10").vw.setTop((int)((65d / 100 * height)));
views.get("label10").vw.setHeight((int)((70d / 100 * height) - ((65d / 100 * height))));
//BA.debugLineNum = 83;BA.debugLine="EditText10.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext10").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext10").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 84;BA.debugLine="EditText10.SetTopAndBottom(65%y,70%y)"[main/320x480,scale=1]
views.get("edittext10").vw.setTop((int)((65d / 100 * height)));
views.get("edittext10").vw.setHeight((int)((70d / 100 * height) - ((65d / 100 * height))));
//BA.debugLineNum = 86;BA.debugLine="Label11.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label11").vw.setLeft((int)((5d / 100 * width)));
views.get("label11").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 87;BA.debugLine="Label11.SetTopAndBottom(70%y,75%y)"[main/320x480,scale=1]
views.get("label11").vw.setTop((int)((70d / 100 * height)));
views.get("label11").vw.setHeight((int)((75d / 100 * height) - ((70d / 100 * height))));
//BA.debugLineNum = 88;BA.debugLine="EditText11.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext11").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext11").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 89;BA.debugLine="EditText11.SetTopAndBottom(70%y,75%y)"[main/320x480,scale=1]
views.get("edittext11").vw.setTop((int)((70d / 100 * height)));
views.get("edittext11").vw.setHeight((int)((75d / 100 * height) - ((70d / 100 * height))));
//BA.debugLineNum = 91;BA.debugLine="Label12.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label12").vw.setLeft((int)((5d / 100 * width)));
views.get("label12").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 92;BA.debugLine="Label12.SetTopAndBottom(75%y,80%y)"[main/320x480,scale=1]
views.get("label12").vw.setTop((int)((75d / 100 * height)));
views.get("label12").vw.setHeight((int)((80d / 100 * height) - ((75d / 100 * height))));
//BA.debugLineNum = 93;BA.debugLine="EditText12.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext12").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext12").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 94;BA.debugLine="EditText12.SetTopAndBottom(75%y,80%y)"[main/320x480,scale=1]
views.get("edittext12").vw.setTop((int)((75d / 100 * height)));
views.get("edittext12").vw.setHeight((int)((80d / 100 * height) - ((75d / 100 * height))));
//BA.debugLineNum = 96;BA.debugLine="Label13.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label13").vw.setLeft((int)((5d / 100 * width)));
views.get("label13").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 97;BA.debugLine="Label13.SetTopAndBottom(80%y,85%y)"[main/320x480,scale=1]
views.get("label13").vw.setTop((int)((80d / 100 * height)));
views.get("label13").vw.setHeight((int)((85d / 100 * height) - ((80d / 100 * height))));
//BA.debugLineNum = 98;BA.debugLine="EditText13.SetLeftAndRight(25%x,50%x)"[main/320x480,scale=1]
views.get("edittext13").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext13").vw.setWidth((int)((50d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 99;BA.debugLine="EditText13.SetTopAndBottom(80%y,85%y)"[main/320x480,scale=1]
views.get("edittext13").vw.setTop((int)((80d / 100 * height)));
views.get("edittext13").vw.setHeight((int)((85d / 100 * height) - ((80d / 100 * height))));
//BA.debugLineNum = 101;BA.debugLine="Label21.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label21").vw.setLeft((int)((50d / 100 * width)));
views.get("label21").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 102;BA.debugLine="Label21.SetTopAndBottom(20%y,25%y)"[main/320x480,scale=1]
views.get("label21").vw.setTop((int)((20d / 100 * height)));
views.get("label21").vw.setHeight((int)((25d / 100 * height) - ((20d / 100 * height))));
//BA.debugLineNum = 103;BA.debugLine="Label22.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label22").vw.setLeft((int)((50d / 100 * width)));
views.get("label22").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 104;BA.debugLine="Label22.SetTopAndBottom(25%y,30%y)"[main/320x480,scale=1]
views.get("label22").vw.setTop((int)((25d / 100 * height)));
views.get("label22").vw.setHeight((int)((30d / 100 * height) - ((25d / 100 * height))));
//BA.debugLineNum = 105;BA.debugLine="Label23.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label23").vw.setLeft((int)((50d / 100 * width)));
views.get("label23").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 106;BA.debugLine="Label23.SetTopAndBottom(30%y,35%y)"[main/320x480,scale=1]
views.get("label23").vw.setTop((int)((30d / 100 * height)));
views.get("label23").vw.setHeight((int)((35d / 100 * height) - ((30d / 100 * height))));
//BA.debugLineNum = 107;BA.debugLine="Label24.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label24").vw.setLeft((int)((50d / 100 * width)));
views.get("label24").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 108;BA.debugLine="Label24.SetTopAndBottom(35%y,40%y)"[main/320x480,scale=1]
views.get("label24").vw.setTop((int)((35d / 100 * height)));
views.get("label24").vw.setHeight((int)((40d / 100 * height) - ((35d / 100 * height))));
//BA.debugLineNum = 109;BA.debugLine="Label25.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label25").vw.setLeft((int)((50d / 100 * width)));
views.get("label25").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 110;BA.debugLine="Label25.SetTopAndBottom(40%y,45%y)"[main/320x480,scale=1]
views.get("label25").vw.setTop((int)((40d / 100 * height)));
views.get("label25").vw.setHeight((int)((45d / 100 * height) - ((40d / 100 * height))));
//BA.debugLineNum = 111;BA.debugLine="Label26.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label26").vw.setLeft((int)((50d / 100 * width)));
views.get("label26").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 112;BA.debugLine="Label26.SetTopAndBottom(45%y,50%y)"[main/320x480,scale=1]
views.get("label26").vw.setTop((int)((45d / 100 * height)));
views.get("label26").vw.setHeight((int)((50d / 100 * height) - ((45d / 100 * height))));
//BA.debugLineNum = 113;BA.debugLine="Label27.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label27").vw.setLeft((int)((50d / 100 * width)));
views.get("label27").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 114;BA.debugLine="Label27.SetTopAndBottom(50%y,55%y)"[main/320x480,scale=1]
views.get("label27").vw.setTop((int)((50d / 100 * height)));
views.get("label27").vw.setHeight((int)((55d / 100 * height) - ((50d / 100 * height))));
//BA.debugLineNum = 115;BA.debugLine="Label28.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label28").vw.setLeft((int)((50d / 100 * width)));
views.get("label28").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 116;BA.debugLine="Label28.SetTopAndBottom(55%y,60%y)"[main/320x480,scale=1]
views.get("label28").vw.setTop((int)((55d / 100 * height)));
views.get("label28").vw.setHeight((int)((60d / 100 * height) - ((55d / 100 * height))));
//BA.debugLineNum = 117;BA.debugLine="Label29.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label29").vw.setLeft((int)((50d / 100 * width)));
views.get("label29").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 118;BA.debugLine="Label29.SetTopAndBottom(60%y,65%y)"[main/320x480,scale=1]
views.get("label29").vw.setTop((int)((60d / 100 * height)));
views.get("label29").vw.setHeight((int)((65d / 100 * height) - ((60d / 100 * height))));
//BA.debugLineNum = 119;BA.debugLine="Label30.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label30").vw.setLeft((int)((50d / 100 * width)));
views.get("label30").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 120;BA.debugLine="Label30.SetTopAndBottom(65%y,70%y)"[main/320x480,scale=1]
views.get("label30").vw.setTop((int)((65d / 100 * height)));
views.get("label30").vw.setHeight((int)((70d / 100 * height) - ((65d / 100 * height))));
//BA.debugLineNum = 121;BA.debugLine="Label31.SetLeftAndRight(50%x,55%x)"[main/320x480,scale=1]
views.get("label31").vw.setLeft((int)((50d / 100 * width)));
views.get("label31").vw.setWidth((int)((55d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 122;BA.debugLine="Label31.SetTopAndBottom(70%y,75%y)"[main/320x480,scale=1]
views.get("label31").vw.setTop((int)((70d / 100 * height)));
views.get("label31").vw.setHeight((int)((75d / 100 * height) - ((70d / 100 * height))));
//BA.debugLineNum = 123;BA.debugLine="Label32.SetLeftAndRight(50%x,60%x)"[main/320x480,scale=1]
views.get("label32").vw.setLeft((int)((50d / 100 * width)));
views.get("label32").vw.setWidth((int)((60d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 124;BA.debugLine="Label32.SetTopAndBottom(75%y,80%y)"[main/320x480,scale=1]
views.get("label32").vw.setTop((int)((75d / 100 * height)));
views.get("label32").vw.setHeight((int)((80d / 100 * height) - ((75d / 100 * height))));
//BA.debugLineNum = 125;BA.debugLine="Label33.SetLeftAndRight(50%x,60%x)"[main/320x480,scale=1]
views.get("label33").vw.setLeft((int)((50d / 100 * width)));
views.get("label33").vw.setWidth((int)((60d / 100 * width) - ((50d / 100 * width))));
//BA.debugLineNum = 126;BA.debugLine="Label33.SetTopAndBottom(80%y,85%y)"[main/320x480,scale=1]
views.get("label33").vw.setTop((int)((80d / 100 * height)));
views.get("label33").vw.setHeight((int)((85d / 100 * height) - ((80d / 100 * height))));
//BA.debugLineNum = 129;BA.debugLine="btnSend.SetLeftAndRight(76%x,99%x)"[main/320x480,scale=1]
views.get("btnsend").vw.setLeft((int)((76d / 100 * width)));
views.get("btnsend").vw.setWidth((int)((99d / 100 * width) - ((76d / 100 * width))));
//BA.debugLineNum = 130;BA.debugLine="btnSend.SetTopAndBottom(85%y,90%y)"[main/320x480,scale=1]
views.get("btnsend").vw.setTop((int)((85d / 100 * height)));
views.get("btnsend").vw.setHeight((int)((90d / 100 * height) - ((85d / 100 * height))));
//BA.debugLineNum = 131;BA.debugLine="txtData.SetLeftAndRight(5%x,75%x)"[main/320x480,scale=1]
views.get("txtdata").vw.setLeft((int)((5d / 100 * width)));
views.get("txtdata").vw.setWidth((int)((75d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 132;BA.debugLine="txtData.SetTopAndBottom(85%y,90%y)"[main/320x480,scale=1]
views.get("txtdata").vw.setTop((int)((85d / 100 * height)));
views.get("txtdata").vw.setHeight((int)((90d / 100 * height) - ((85d / 100 * height))));
//BA.debugLineNum = 133;BA.debugLine="Label18.SetLeftAndRight(5%x,25%x)"[main/320x480,scale=1]
views.get("label18").vw.setLeft((int)((5d / 100 * width)));
views.get("label18").vw.setWidth((int)((25d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 134;BA.debugLine="Label18.SetTopAndBottom(90%y,93%y)"[main/320x480,scale=1]
views.get("label18").vw.setTop((int)((90d / 100 * height)));
views.get("label18").vw.setHeight((int)((93d / 100 * height) - ((90d / 100 * height))));
//BA.debugLineNum = 135;BA.debugLine="EditText14.SetLeftAndRight(5%x,95%x)"[main/320x480,scale=1]
views.get("edittext14").vw.setLeft((int)((5d / 100 * width)));
views.get("edittext14").vw.setWidth((int)((95d / 100 * width) - ((5d / 100 * width))));
//BA.debugLineNum = 136;BA.debugLine="EditText14.SetTopAndBottom(92%y,99%y)"[main/320x480,scale=1]
views.get("edittext14").vw.setTop((int)((92d / 100 * height)));
views.get("edittext14").vw.setHeight((int)((99d / 100 * height) - ((92d / 100 * height))));

}
public static void LS_general(anywheresoftware.b4a.BA ba, android.view.View parent, anywheresoftware.b4a.keywords.LayoutValues lv, java.util.Map props,
java.util.Map<String, anywheresoftware.b4a.keywords.LayoutBuilder.ViewWrapperAndAnchor> views, int width, int height, float scale) throws Exception {
anywheresoftware.b4a.keywords.LayoutBuilder.setScaleRate(0.3);
anywheresoftware.b4a.keywords.LayoutBuilder.scaleAll(views);

}
}