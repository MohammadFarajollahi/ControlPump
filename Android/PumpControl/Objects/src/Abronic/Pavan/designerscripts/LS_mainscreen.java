package Abronic.Pavan.designerscripts;
import anywheresoftware.b4a.objects.TextViewWrapper;
import anywheresoftware.b4a.objects.ImageViewWrapper;
import anywheresoftware.b4a.BA;


public class LS_mainscreen{

public static void LS_320x480_1(anywheresoftware.b4a.BA ba, android.view.View parent, anywheresoftware.b4a.keywords.LayoutValues lv, java.util.Map props,
java.util.Map<String, anywheresoftware.b4a.keywords.LayoutBuilder.ViewWrapperAndAnchor> views, int width, int height, float scale) throws Exception {
anywheresoftware.b4a.keywords.LayoutBuilder.setScaleRate(0.3);
views.get("imageview3").vw.setLeft((int)((0d / 100 * width)));
views.get("imageview3").vw.setWidth((int)((20d / 100 * width) - ((0d / 100 * width))));
views.get("imageview3").vw.setTop((int)((0d / 100 * height)));
views.get("imageview3").vw.setHeight((int)((7d / 100 * height) - ((0d / 100 * height))));
views.get("label40").vw.setLeft((int)((20d / 100 * width)));
views.get("label40").vw.setWidth((int)((60d / 100 * width) - ((20d / 100 * width))));
views.get("label40").vw.setTop((int)((1d / 100 * height)));
views.get("label40").vw.setHeight((int)((6d / 100 * height) - ((1d / 100 * height))));
views.get("imageview1").vw.setLeft((int)((38d / 100 * width)));
views.get("imageview1").vw.setWidth((int)((45d / 100 * width) - ((38d / 100 * width))));
views.get("imageview1").vw.setTop((int)((11d / 100 * height)));
views.get("imageview1").vw.setHeight((int)((15d / 100 * height) - ((11d / 100 * height))));
views.get("button1").vw.setLeft((int)((6d / 100 * width)));
views.get("button1").vw.setWidth((int)((35d / 100 * width) - ((6d / 100 * width))));
views.get("button1").vw.setTop((int)((10d / 100 * height)));
views.get("button1").vw.setHeight((int)((16d / 100 * height) - ((10d / 100 * height))));
views.get("imageview5").vw.setLeft((int)((5d / 100 * width)));
views.get("imageview5").vw.setWidth((int)((50d / 100 * width) - ((5d / 100 * width))));
views.get("imageview5").vw.setTop((int)((18d / 100 * height)));
views.get("imageview5").vw.setHeight((int)((27d / 100 * height) - ((18d / 100 * height))));
views.get("label41").vw.setLeft((int)((5d / 100 * width)));
views.get("label41").vw.setWidth((int)((50d / 100 * width) - ((5d / 100 * width))));
views.get("label41").vw.setTop((int)((20d / 100 * height)));
views.get("label41").vw.setHeight((int)((25d / 100 * height) - ((20d / 100 * height))));
views.get("panel1").vw.setLeft((int)((1d / 100 * width)));
views.get("panel1").vw.setWidth((int)((99d / 100 * width) - ((1d / 100 * width))));
views.get("panel1").vw.setTop((int)((10d / 100 * height)));
views.get("panel1").vw.setHeight((int)((90d / 100 * height) - ((10d / 100 * height))));
views.get("lstdevices").vw.setLeft((int)((1d / 100 * width)));
views.get("lstdevices").vw.setWidth((int)((98d / 100 * width) - ((1d / 100 * width))));
views.get("lstdevices").vw.setTop((int)((6d / 100 * height)));
views.get("lstdevices").vw.setHeight((int)((73d / 100 * height) - ((6d / 100 * height))));
views.get("close").vw.setLeft((int)((30d / 100 * width)));
views.get("close").vw.setWidth((int)((70d / 100 * width) - ((30d / 100 * width))));
views.get("close").vw.setTop((int)((74d / 100 * height)));
views.get("close").vw.setHeight((int)((80d / 100 * height) - ((74d / 100 * height))));
views.get("label13").vw.setLeft((int)((15d / 100 * width)));
views.get("label13").vw.setWidth((int)((75d / 100 * width) - ((15d / 100 * width))));
views.get("label13").vw.setTop((int)((1d / 100 * height)));
views.get("label13").vw.setHeight((int)((6d / 100 * height) - ((1d / 100 * height))));
views.get("imageview2").vw.setLeft((int)((50d / 100 * width)));
views.get("imageview2").vw.setWidth((int)((97d / 100 * width) - ((50d / 100 * width))));
views.get("imageview2").vw.setTop((int)((0d / 100 * height)));
views.get("imageview2").vw.setHeight((int)((25d / 100 * height) - ((0d / 100 * height))));
views.get("label1").vw.setLeft((int)((55d / 100 * width)));
views.get("label1").vw.setWidth((int)((93d / 100 * width) - ((55d / 100 * width))));
views.get("label1").vw.setTop((int)((1d / 100 * height)));
views.get("label1").vw.setHeight((int)((6d / 100 * height) - ((1d / 100 * height))));
views.get("label2").vw.setLeft((int)((70d / 100 * width)));
views.get("label2").vw.setWidth((int)((93d / 100 * width) - ((70d / 100 * width))));
views.get("label2").vw.setTop((int)((5d / 100 * height)));
views.get("label2").vw.setHeight((int)((9d / 100 * height) - ((5d / 100 * height))));
views.get("label6").vw.setLeft((int)((66d / 100 * width)));
views.get("label6").vw.setWidth((int)((75d / 100 * width) - ((66d / 100 * width))));
views.get("label6").vw.setTop((int)((5d / 100 * height)));
views.get("label6").vw.setHeight((int)((9d / 100 * height) - ((5d / 100 * height))));
views.get("label3").vw.setLeft((int)((70d / 100 * width)));
views.get("label3").vw.setWidth((int)((93d / 100 * width) - ((70d / 100 * width))));
views.get("label3").vw.setTop((int)((9d / 100 * height)));
views.get("label3").vw.setHeight((int)((12d / 100 * height) - ((9d / 100 * height))));
views.get("label7").vw.setLeft((int)((66d / 100 * width)));
views.get("label7").vw.setWidth((int)((75d / 100 * width) - ((66d / 100 * width))));
views.get("label7").vw.setTop((int)((9d / 100 * height)));
views.get("label7").vw.setHeight((int)((12d / 100 * height) - ((9d / 100 * height))));
views.get("label4").vw.setLeft((int)((70d / 100 * width)));
views.get("label4").vw.setWidth((int)((93d / 100 * width) - ((70d / 100 * width))));
views.get("label4").vw.setTop((int)((12d / 100 * height)));
views.get("label4").vw.setHeight((int)((15d / 100 * height) - ((12d / 100 * height))));
views.get("label8").vw.setLeft((int)((66d / 100 * width)));
views.get("label8").vw.setWidth((int)((75d / 100 * width) - ((66d / 100 * width))));
views.get("label8").vw.setTop((int)((12d / 100 * height)));
views.get("label8").vw.setHeight((int)((15d / 100 * height) - ((12d / 100 * height))));
views.get("label5").vw.setLeft((int)((70d / 100 * width)));
views.get("label5").vw.setWidth((int)((93d / 100 * width) - ((70d / 100 * width))));
views.get("label5").vw.setTop((int)((15d / 100 * height)));
views.get("label5").vw.setHeight((int)((19d / 100 * height) - ((15d / 100 * height))));
views.get("label9").vw.setLeft((int)((60d / 100 * width)));
views.get("label9").vw.setWidth((int)((72d / 100 * width) - ((60d / 100 * width))));
views.get("label9").vw.setTop((int)((15d / 100 * height)));
views.get("label9").vw.setHeight((int)((19d / 100 * height) - ((15d / 100 * height))));
views.get("label10").vw.setLeft((int)((59d / 100 * width)));
views.get("label10").vw.setWidth((int)((62d / 100 * width) - ((59d / 100 * width))));
views.get("label10").vw.setTop((int)((15d / 100 * height)));
views.get("label10").vw.setHeight((int)((19d / 100 * height) - ((15d / 100 * height))));
views.get("label11").vw.setLeft((int)((49d / 100 * width)));
views.get("label11").vw.setWidth((int)((60d / 100 * width) - ((49d / 100 * width))));
views.get("label11").vw.setTop((int)((15d / 100 * height)));
views.get("label11").vw.setHeight((int)((19d / 100 * height) - ((15d / 100 * height))));
views.get("label12").vw.setLeft((int)((52d / 100 * width)));
views.get("label12").vw.setWidth((int)((95d / 100 * width) - ((52d / 100 * width))));
views.get("label12").vw.setTop((int)((18d / 100 * height)));
views.get("label12").vw.setHeight((int)((24d / 100 * height) - ((18d / 100 * height))));
views.get("label14").vw.setLeft((int)((2d / 100 * width)));
views.get("label14").vw.setWidth((int)((25d / 100 * width) - ((2d / 100 * width))));
views.get("label14").vw.setTop((int)((30d / 100 * height)));
views.get("label14").vw.setHeight((int)((35d / 100 * height) - ((30d / 100 * height))));
views.get("edittext1").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext1").vw.setWidth((int)((40d / 100 * width) - ((25d / 100 * width))));
views.get("edittext1").vw.setTop((int)((30d / 100 * height)));
views.get("edittext1").vw.setHeight((int)((35d / 100 * height) - ((30d / 100 * height))));
views.get("label27").vw.setLeft((int)((40d / 100 * width)));
views.get("label27").vw.setWidth((int)((43d / 100 * width) - ((40d / 100 * width))));
views.get("label27").vw.setTop((int)((30d / 100 * height)));
views.get("label27").vw.setHeight((int)((35d / 100 * height) - ((30d / 100 * height))));
views.get("label15").vw.setLeft((int)((1d / 100 * width)));
views.get("label15").vw.setWidth((int)((25d / 100 * width) - ((1d / 100 * width))));
views.get("label15").vw.setTop((int)((37d / 100 * height)));
views.get("label15").vw.setHeight((int)((43d / 100 * height) - ((37d / 100 * height))));
views.get("edittext2").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext2").vw.setWidth((int)((40d / 100 * width) - ((25d / 100 * width))));
views.get("edittext2").vw.setTop((int)((37d / 100 * height)));
views.get("edittext2").vw.setHeight((int)((42d / 100 * height) - ((37d / 100 * height))));
views.get("label28").vw.setLeft((int)((38d / 100 * width)));
views.get("label28").vw.setWidth((int)((46d / 100 * width) - ((38d / 100 * width))));
views.get("label28").vw.setTop((int)((37d / 100 * height)));
views.get("label28").vw.setHeight((int)((42d / 100 * height) - ((37d / 100 * height))));
views.get("label42").vw.setLeft((int)((46d / 100 * width)));
views.get("label42").vw.setWidth((int)((52d / 100 * width) - ((46d / 100 * width))));
views.get("label42").vw.setTop((int)((37d / 100 * height)));
views.get("label42").vw.setHeight((int)((42d / 100 * height) - ((37d / 100 * height))));
views.get("label16").vw.setLeft((int)((50d / 100 * width)));
views.get("label16").vw.setWidth((int)((75d / 100 * width) - ((50d / 100 * width))));
views.get("label16").vw.setTop((int)((35d / 100 * height)));
views.get("label16").vw.setHeight((int)((45d / 100 * height) - ((35d / 100 * height))));
views.get("edittext3").vw.setLeft((int)((75d / 100 * width)));
views.get("edittext3").vw.setWidth((int)((90d / 100 * width) - ((75d / 100 * width))));
views.get("edittext3").vw.setTop((int)((37d / 100 * height)));
views.get("edittext3").vw.setHeight((int)((42d / 100 * height) - ((37d / 100 * height))));
views.get("label29").vw.setLeft((int)((90d / 100 * width)));
views.get("label29").vw.setWidth((int)((100d / 100 * width) - ((90d / 100 * width))));
views.get("label29").vw.setTop((int)((37d / 100 * height)));
views.get("label29").vw.setHeight((int)((42d / 100 * height) - ((37d / 100 * height))));
views.get("label18").vw.setLeft((int)((1d / 100 * width)));
views.get("label18").vw.setWidth((int)((25d / 100 * width) - ((1d / 100 * width))));
views.get("label18").vw.setTop((int)((44d / 100 * height)));
views.get("label18").vw.setHeight((int)((49d / 100 * height) - ((44d / 100 * height))));
views.get("edittext5").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext5").vw.setWidth((int)((40d / 100 * width) - ((25d / 100 * width))));
views.get("edittext5").vw.setTop((int)((44d / 100 * height)));
views.get("edittext5").vw.setHeight((int)((49d / 100 * height) - ((44d / 100 * height))));
views.get("label31").vw.setLeft((int)((38d / 100 * width)));
views.get("label31").vw.setWidth((int)((46d / 100 * width) - ((38d / 100 * width))));
views.get("label31").vw.setTop((int)((44d / 100 * height)));
views.get("label31").vw.setHeight((int)((49d / 100 * height) - ((44d / 100 * height))));
views.get("label43").vw.setLeft((int)((46d / 100 * width)));
views.get("label43").vw.setWidth((int)((52d / 100 * width) - ((46d / 100 * width))));
views.get("label43").vw.setTop((int)((44d / 100 * height)));
views.get("label43").vw.setHeight((int)((49d / 100 * height) - ((44d / 100 * height))));
views.get("label17").vw.setLeft((int)((50d / 100 * width)));
views.get("label17").vw.setWidth((int)((75d / 100 * width) - ((50d / 100 * width))));
views.get("label17").vw.setTop((int)((44d / 100 * height)));
views.get("label17").vw.setHeight((int)((49d / 100 * height) - ((44d / 100 * height))));
views.get("edittext4").vw.setLeft((int)((75d / 100 * width)));
views.get("edittext4").vw.setWidth((int)((90d / 100 * width) - ((75d / 100 * width))));
views.get("edittext4").vw.setTop((int)((44d / 100 * height)));
views.get("edittext4").vw.setHeight((int)((49d / 100 * height) - ((44d / 100 * height))));
views.get("label30").vw.setLeft((int)((90d / 100 * width)));
views.get("label30").vw.setWidth((int)((100d / 100 * width) - ((90d / 100 * width))));
views.get("label30").vw.setTop((int)((44d / 100 * height)));
views.get("label30").vw.setHeight((int)((49d / 100 * height) - ((44d / 100 * height))));
views.get("label19").vw.setLeft((int)((1d / 100 * width)));
views.get("label19").vw.setWidth((int)((26d / 100 * width) - ((1d / 100 * width))));
views.get("label19").vw.setTop((int)((51d / 100 * height)));
views.get("label19").vw.setHeight((int)((56d / 100 * height) - ((51d / 100 * height))));
views.get("edittext6").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext6").vw.setWidth((int)((40d / 100 * width) - ((25d / 100 * width))));
views.get("edittext6").vw.setTop((int)((51d / 100 * height)));
views.get("edittext6").vw.setHeight((int)((56d / 100 * height) - ((51d / 100 * height))));
views.get("label32").vw.setLeft((int)((38d / 100 * width)));
views.get("label32").vw.setWidth((int)((46d / 100 * width) - ((38d / 100 * width))));
views.get("label32").vw.setTop((int)((51d / 100 * height)));
views.get("label32").vw.setHeight((int)((56d / 100 * height) - ((51d / 100 * height))));
views.get("label20").vw.setLeft((int)((50d / 100 * width)));
views.get("label20").vw.setWidth((int)((75d / 100 * width) - ((50d / 100 * width))));
views.get("label20").vw.setTop((int)((51d / 100 * height)));
views.get("label20").vw.setHeight((int)((56d / 100 * height) - ((51d / 100 * height))));
views.get("edittext7").vw.setLeft((int)((75d / 100 * width)));
views.get("edittext7").vw.setWidth((int)((90d / 100 * width) - ((75d / 100 * width))));
views.get("edittext7").vw.setTop((int)((51d / 100 * height)));
views.get("edittext7").vw.setHeight((int)((56d / 100 * height) - ((51d / 100 * height))));
views.get("label33").vw.setLeft((int)((90d / 100 * width)));
views.get("label33").vw.setWidth((int)((100d / 100 * width) - ((90d / 100 * width))));
views.get("label33").vw.setTop((int)((51d / 100 * height)));
views.get("label33").vw.setHeight((int)((56d / 100 * height) - ((51d / 100 * height))));
views.get("label22").vw.setLeft((int)((1d / 100 * width)));
views.get("label22").vw.setWidth((int)((26d / 100 * width) - ((1d / 100 * width))));
views.get("label22").vw.setTop((int)((58d / 100 * height)));
views.get("label22").vw.setHeight((int)((63d / 100 * height) - ((58d / 100 * height))));
views.get("edittext9").vw.setLeft((int)((25d / 100 * width)));
views.get("edittext9").vw.setWidth((int)((40d / 100 * width) - ((25d / 100 * width))));
views.get("edittext9").vw.setTop((int)((57d / 100 * height)));
views.get("edittext9").vw.setHeight((int)((63d / 100 * height) - ((57d / 100 * height))));
views.get("label35").vw.setLeft((int)((38d / 100 * width)));
views.get("label35").vw.setWidth((int)((46d / 100 * width) - ((38d / 100 * width))));
views.get("label35").vw.setTop((int)((58d / 100 * height)));
views.get("label35").vw.setHeight((int)((63d / 100 * height) - ((58d / 100 * height))));
views.get("label23").vw.setLeft((int)((50d / 100 * width)));
views.get("label23").vw.setWidth((int)((75d / 100 * width) - ((50d / 100 * width))));
views.get("label23").vw.setTop((int)((58d / 100 * height)));
views.get("label23").vw.setHeight((int)((63d / 100 * height) - ((58d / 100 * height))));
views.get("edittext10").vw.setLeft((int)((75d / 100 * width)));
views.get("edittext10").vw.setWidth((int)((90d / 100 * width) - ((75d / 100 * width))));
views.get("edittext10").vw.setTop((int)((58d / 100 * height)));
views.get("edittext10").vw.setHeight((int)((63d / 100 * height) - ((58d / 100 * height))));
views.get("label36").vw.setLeft((int)((90d / 100 * width)));
views.get("label36").vw.setWidth((int)((100d / 100 * width) - ((90d / 100 * width))));
views.get("label36").vw.setTop((int)((58d / 100 * height)));
views.get("label36").vw.setHeight((int)((63d / 100 * height) - ((58d / 100 * height))));
views.get("label21").vw.setLeft((int)((28d / 100 * width)));
views.get("label21").vw.setWidth((int)((44d / 100 * width) - ((28d / 100 * width))));
views.get("label21").vw.setTop((int)((65d / 100 * height)));
views.get("label21").vw.setHeight((int)((70d / 100 * height) - ((65d / 100 * height))));
views.get("edittext8").vw.setLeft((int)((44d / 100 * width)));
views.get("edittext8").vw.setWidth((int)((61d / 100 * width) - ((44d / 100 * width))));
views.get("edittext8").vw.setTop((int)((65d / 100 * height)));
views.get("edittext8").vw.setHeight((int)((70d / 100 * height) - ((65d / 100 * height))));
views.get("label34").vw.setLeft((int)((61d / 100 * width)));
views.get("label34").vw.setWidth((int)((65d / 100 * width) - ((61d / 100 * width))));
views.get("label34").vw.setTop((int)((65d / 100 * height)));
views.get("label34").vw.setHeight((int)((70d / 100 * height) - ((65d / 100 * height))));
views.get("label24").vw.setLeft((int)((1d / 100 * width)));
views.get("label24").vw.setWidth((int)((30d / 100 * width) - ((1d / 100 * width))));
views.get("label24").vw.setTop((int)((72d / 100 * height)));
views.get("label24").vw.setHeight((int)((75d / 100 * height) - ((72d / 100 * height))));
views.get("edittext11").vw.setLeft((int)((30d / 100 * width)));
views.get("edittext11").vw.setWidth((int)((45d / 100 * width) - ((30d / 100 * width))));
//BA.debugLineNum = 156;BA.debugLine="EditText11.SetTopAndBottom(71%y,76%y)"[MainScreen/320x480,scale=1]
views.get("edittext11").vw.setTop((int)((71d / 100 * height)));
views.get("edittext11").vw.setHeight((int)((76d / 100 * height) - ((71d / 100 * height))));
//BA.debugLineNum = 157;BA.debugLine="Label37.SetLeftAndRight(45%x,55%x)"[MainScreen/320x480,scale=1]
views.get("label37").vw.setLeft((int)((45d / 100 * width)));
views.get("label37").vw.setWidth((int)((55d / 100 * width) - ((45d / 100 * width))));
//BA.debugLineNum = 158;BA.debugLine="Label37.SetTopAndBottom(72%y,75%y)"[MainScreen/320x480,scale=1]
views.get("label37").vw.setTop((int)((72d / 100 * height)));
views.get("label37").vw.setHeight((int)((75d / 100 * height) - ((72d / 100 * height))));
//BA.debugLineNum = 162;BA.debugLine="Label25.SetLeftAndRight(1%x,30%x)"[MainScreen/320x480,scale=1]
views.get("label25").vw.setLeft((int)((1d / 100 * width)));
views.get("label25").vw.setWidth((int)((30d / 100 * width) - ((1d / 100 * width))));
//BA.debugLineNum = 163;BA.debugLine="Label25.SetTopAndBottom(77%y,82%y)"[MainScreen/320x480,scale=1]
views.get("label25").vw.setTop((int)((77d / 100 * height)));
views.get("label25").vw.setHeight((int)((82d / 100 * height) - ((77d / 100 * height))));
//BA.debugLineNum = 164;BA.debugLine="EditText12.SetLeftAndRight(30%x,45%x)"[MainScreen/320x480,scale=1]
views.get("edittext12").vw.setLeft((int)((30d / 100 * width)));
views.get("edittext12").vw.setWidth((int)((45d / 100 * width) - ((30d / 100 * width))));
//BA.debugLineNum = 165;BA.debugLine="EditText12.SetTopAndBottom(77%y,82%y)"[MainScreen/320x480,scale=1]
views.get("edittext12").vw.setTop((int)((77d / 100 * height)));
views.get("edittext12").vw.setHeight((int)((82d / 100 * height) - ((77d / 100 * height))));
//BA.debugLineNum = 166;BA.debugLine="Label38.SetLeftAndRight(45%x,55%x)"[MainScreen/320x480,scale=1]
views.get("label38").vw.setLeft((int)((45d / 100 * width)));
views.get("label38").vw.setWidth((int)((55d / 100 * width) - ((45d / 100 * width))));
//BA.debugLineNum = 167;BA.debugLine="Label38.SetTopAndBottom(77%y,82%y)"[MainScreen/320x480,scale=1]
views.get("label38").vw.setTop((int)((77d / 100 * height)));
views.get("label38").vw.setHeight((int)((82d / 100 * height) - ((77d / 100 * height))));
//BA.debugLineNum = 171;BA.debugLine="Label26.SetLeftAndRight(1%x,30%x)"[MainScreen/320x480,scale=1]
views.get("label26").vw.setLeft((int)((1d / 100 * width)));
views.get("label26").vw.setWidth((int)((30d / 100 * width) - ((1d / 100 * width))));
//BA.debugLineNum = 172;BA.debugLine="Label26.SetTopAndBottom(84%y,89%y)"[MainScreen/320x480,scale=1]
views.get("label26").vw.setTop((int)((84d / 100 * height)));
views.get("label26").vw.setHeight((int)((89d / 100 * height) - ((84d / 100 * height))));
//BA.debugLineNum = 177;BA.debugLine="Spinner1.SetLeftAndRight(25%x,55%x)"[MainScreen/320x480,scale=1]
views.get("spinner1").vw.setLeft((int)((25d / 100 * width)));
views.get("spinner1").vw.setWidth((int)((55d / 100 * width) - ((25d / 100 * width))));
//BA.debugLineNum = 178;BA.debugLine="Spinner1.SetTopAndBottom(83%y,90%y)"[MainScreen/320x480,scale=1]
views.get("spinner1").vw.setTop((int)((83d / 100 * height)));
views.get("spinner1").vw.setHeight((int)((90d / 100 * height) - ((83d / 100 * height))));
//BA.debugLineNum = 181;BA.debugLine="Button2.SetLeftAndRight(10%x,40%x)"[MainScreen/320x480,scale=1]
views.get("button2").vw.setLeft((int)((10d / 100 * width)));
views.get("button2").vw.setWidth((int)((40d / 100 * width) - ((10d / 100 * width))));
//BA.debugLineNum = 182;BA.debugLine="Button2.SetTopAndBottom(93%y,99%y)"[MainScreen/320x480,scale=1]
views.get("button2").vw.setTop((int)((93d / 100 * height)));
views.get("button2").vw.setHeight((int)((99d / 100 * height) - ((93d / 100 * height))));
//BA.debugLineNum = 184;BA.debugLine="Button3.SetLeftAndRight(60%x,90%x)"[MainScreen/320x480,scale=1]
views.get("button3").vw.setLeft((int)((60d / 100 * width)));
views.get("button3").vw.setWidth((int)((90d / 100 * width) - ((60d / 100 * width))));
//BA.debugLineNum = 185;BA.debugLine="Button3.SetTopAndBottom(93%y,99%y)"[MainScreen/320x480,scale=1]
views.get("button3").vw.setTop((int)((93d / 100 * height)));
views.get("button3").vw.setHeight((int)((99d / 100 * height) - ((93d / 100 * height))));

}
public static void LS_general(anywheresoftware.b4a.BA ba, android.view.View parent, anywheresoftware.b4a.keywords.LayoutValues lv, java.util.Map props,
java.util.Map<String, anywheresoftware.b4a.keywords.LayoutBuilder.ViewWrapperAndAnchor> views, int width, int height, float scale) throws Exception {
anywheresoftware.b4a.keywords.LayoutBuilder.setScaleRate(0.3);
anywheresoftware.b4a.keywords.LayoutBuilder.scaleAll(views);

}
}