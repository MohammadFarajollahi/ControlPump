package Abronic.Pavan;


import anywheresoftware.b4a.B4AMenuItem;
import android.app.Activity;
import android.os.Bundle;
import anywheresoftware.b4a.BA;
import anywheresoftware.b4a.BALayout;
import anywheresoftware.b4a.B4AActivity;
import anywheresoftware.b4a.ObjectWrapper;
import anywheresoftware.b4a.objects.ActivityWrapper;
import java.lang.reflect.InvocationTargetException;
import anywheresoftware.b4a.B4AUncaughtException;
import anywheresoftware.b4a.debug.*;
import java.lang.ref.WeakReference;

public class mainscreen extends Activity implements B4AActivity{
	public static mainscreen mostCurrent;
	static boolean afterFirstLayout;
	static boolean isFirst = true;
    private static boolean processGlobalsRun = false;
	BALayout layout;
	public static BA processBA;
	BA activityBA;
    ActivityWrapper _activity;
    java.util.ArrayList<B4AMenuItem> menuItems;
	public static final boolean fullScreen = false;
	public static final boolean includeTitle = false;
    public static WeakReference<Activity> previousOne;
    public static boolean dontPause;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
        mostCurrent = this;
		if (processBA == null) {
			processBA = new BA(this.getApplicationContext(), null, null, "Abronic.Pavan", "Abronic.Pavan.mainscreen");
			processBA.loadHtSubs(this.getClass());
	        float deviceScale = getApplicationContext().getResources().getDisplayMetrics().density;
	        BALayout.setDeviceScale(deviceScale);
            
		}
		else if (previousOne != null) {
			Activity p = previousOne.get();
			if (p != null && p != this) {
                BA.LogInfo("Killing previous instance (mainscreen).");
				p.finish();
			}
		}
        processBA.setActivityPaused(true);
        processBA.runHook("oncreate", this, null);
		if (!includeTitle) {
        	this.getWindow().requestFeature(android.view.Window.FEATURE_NO_TITLE);
        }
        if (fullScreen) {
        	getWindow().setFlags(android.view.WindowManager.LayoutParams.FLAG_FULLSCREEN,   
        			android.view.WindowManager.LayoutParams.FLAG_FULLSCREEN);
        }
		
        processBA.sharedProcessBA.activityBA = null;
		layout = new BALayout(this);
		setContentView(layout);
		afterFirstLayout = false;
        WaitForLayout wl = new WaitForLayout();
        if (anywheresoftware.b4a.objects.ServiceHelper.StarterHelper.startFromActivity(this, processBA, wl, false))
		    BA.handler.postDelayed(wl, 5);

	}
	static class WaitForLayout implements Runnable {
		public void run() {
			if (afterFirstLayout)
				return;
			if (mostCurrent == null)
				return;
            
			if (mostCurrent.layout.getWidth() == 0) {
				BA.handler.postDelayed(this, 5);
				return;
			}
			mostCurrent.layout.getLayoutParams().height = mostCurrent.layout.getHeight();
			mostCurrent.layout.getLayoutParams().width = mostCurrent.layout.getWidth();
			afterFirstLayout = true;
			mostCurrent.afterFirstLayout();
		}
	}
	private void afterFirstLayout() {
        if (this != mostCurrent)
			return;
		activityBA = new BA(this, layout, processBA, "Abronic.Pavan", "Abronic.Pavan.mainscreen");
        
        processBA.sharedProcessBA.activityBA = new java.lang.ref.WeakReference<BA>(activityBA);
        anywheresoftware.b4a.objects.ViewWrapper.lastId = 0;
        _activity = new ActivityWrapper(activityBA, "activity");
        anywheresoftware.b4a.Msgbox.isDismissing = false;
        if (BA.isShellModeRuntimeCheck(processBA)) {
			if (isFirst)
				processBA.raiseEvent2(null, true, "SHELL", false);
			processBA.raiseEvent2(null, true, "CREATE", true, "Abronic.Pavan.mainscreen", processBA, activityBA, _activity, anywheresoftware.b4a.keywords.Common.Density, mostCurrent);
			_activity.reinitializeForShell(activityBA, "activity");
		}
        initializeProcessGlobals();		
        initializeGlobals();
        
        BA.LogInfo("** Activity (mainscreen) Create " + (isFirst ? "(first time)" : "") + " **");
        processBA.raiseEvent2(null, true, "activity_create", false, isFirst);
		isFirst = false;
		if (this != mostCurrent)
			return;
        processBA.setActivityPaused(false);
        BA.LogInfo("** Activity (mainscreen) Resume **");
        processBA.raiseEvent(null, "activity_resume");
        if (android.os.Build.VERSION.SDK_INT >= 11) {
			try {
				android.app.Activity.class.getMethod("invalidateOptionsMenu").invoke(this,(Object[]) null);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}

	}
	public void addMenuItem(B4AMenuItem item) {
		if (menuItems == null)
			menuItems = new java.util.ArrayList<B4AMenuItem>();
		menuItems.add(item);
	}
	@Override
	public boolean onCreateOptionsMenu(android.view.Menu menu) {
		super.onCreateOptionsMenu(menu);
        try {
            if (processBA.subExists("activity_actionbarhomeclick")) {
                Class.forName("android.app.ActionBar").getMethod("setHomeButtonEnabled", boolean.class).invoke(
                    getClass().getMethod("getActionBar").invoke(this), true);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        if (processBA.runHook("oncreateoptionsmenu", this, new Object[] {menu}))
            return true;
		if (menuItems == null)
			return false;
		for (B4AMenuItem bmi : menuItems) {
			android.view.MenuItem mi = menu.add(bmi.title);
			if (bmi.drawable != null)
				mi.setIcon(bmi.drawable);
            if (android.os.Build.VERSION.SDK_INT >= 11) {
				try {
                    if (bmi.addToBar) {
				        android.view.MenuItem.class.getMethod("setShowAsAction", int.class).invoke(mi, 1);
                    }
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
			mi.setOnMenuItemClickListener(new B4AMenuItemsClickListener(bmi.eventName.toLowerCase(BA.cul)));
		}
        
		return true;
	}   
 @Override
 public boolean onOptionsItemSelected(android.view.MenuItem item) {
    if (item.getItemId() == 16908332) {
        processBA.raiseEvent(null, "activity_actionbarhomeclick");
        return true;
    }
    else
        return super.onOptionsItemSelected(item); 
}
@Override
 public boolean onPrepareOptionsMenu(android.view.Menu menu) {
    super.onPrepareOptionsMenu(menu);
    processBA.runHook("onprepareoptionsmenu", this, new Object[] {menu});
    return true;
    
 }
 protected void onStart() {
    super.onStart();
    processBA.runHook("onstart", this, null);
}
 protected void onStop() {
    super.onStop();
    processBA.runHook("onstop", this, null);
}
    public void onWindowFocusChanged(boolean hasFocus) {
       super.onWindowFocusChanged(hasFocus);
       if (processBA.subExists("activity_windowfocuschanged"))
           processBA.raiseEvent2(null, true, "activity_windowfocuschanged", false, hasFocus);
    }
	private class B4AMenuItemsClickListener implements android.view.MenuItem.OnMenuItemClickListener {
		private final String eventName;
		public B4AMenuItemsClickListener(String eventName) {
			this.eventName = eventName;
		}
		public boolean onMenuItemClick(android.view.MenuItem item) {
			processBA.raiseEventFromUI(item.getTitle(), eventName + "_click");
			return true;
		}
	}
    public static Class<?> getObject() {
		return mainscreen.class;
	}
    private Boolean onKeySubExist = null;
    private Boolean onKeyUpSubExist = null;
	@Override
	public boolean onKeyDown(int keyCode, android.view.KeyEvent event) {
        if (processBA.runHook("onkeydown", this, new Object[] {keyCode, event}))
            return true;
		if (onKeySubExist == null)
			onKeySubExist = processBA.subExists("activity_keypress");
		if (onKeySubExist) {
			if (keyCode == anywheresoftware.b4a.keywords.constants.KeyCodes.KEYCODE_BACK &&
					android.os.Build.VERSION.SDK_INT >= 18) {
				HandleKeyDelayed hk = new HandleKeyDelayed();
				hk.kc = keyCode;
				BA.handler.post(hk);
				return true;
			}
			else {
				boolean res = new HandleKeyDelayed().runDirectly(keyCode);
				if (res)
					return true;
			}
		}
		return super.onKeyDown(keyCode, event);
	}
	private class HandleKeyDelayed implements Runnable {
		int kc;
		public void run() {
			runDirectly(kc);
		}
		public boolean runDirectly(int keyCode) {
			Boolean res =  (Boolean)processBA.raiseEvent2(_activity, false, "activity_keypress", false, keyCode);
			if (res == null || res == true) {
                return true;
            }
            else if (keyCode == anywheresoftware.b4a.keywords.constants.KeyCodes.KEYCODE_BACK) {
				finish();
				return true;
			}
            return false;
		}
		
	}
    @Override
	public boolean onKeyUp(int keyCode, android.view.KeyEvent event) {
        if (processBA.runHook("onkeyup", this, new Object[] {keyCode, event}))
            return true;
		if (onKeyUpSubExist == null)
			onKeyUpSubExist = processBA.subExists("activity_keyup");
		if (onKeyUpSubExist) {
			Boolean res =  (Boolean)processBA.raiseEvent2(_activity, false, "activity_keyup", false, keyCode);
			if (res == null || res == true)
				return true;
		}
		return super.onKeyUp(keyCode, event);
	}
	@Override
	public void onNewIntent(android.content.Intent intent) {
        super.onNewIntent(intent);
		this.setIntent(intent);
        processBA.runHook("onnewintent", this, new Object[] {intent});
	}
    @Override 
	public void onPause() {
		super.onPause();
        if (_activity == null)
            return;
        if (this != mostCurrent)
			return;
		anywheresoftware.b4a.Msgbox.dismiss(true);
        if (!dontPause)
            BA.LogInfo("** Activity (mainscreen) Pause, UserClosed = " + activityBA.activity.isFinishing() + " **");
        else
            BA.LogInfo("** Activity (mainscreen) Pause event (activity is not paused). **");
        if (mostCurrent != null)
            processBA.raiseEvent2(_activity, true, "activity_pause", false, activityBA.activity.isFinishing());		
        if (!dontPause) {
            processBA.setActivityPaused(true);
            mostCurrent = null;
        }

        if (!activityBA.activity.isFinishing())
			previousOne = new WeakReference<Activity>(this);
        anywheresoftware.b4a.Msgbox.isDismissing = false;
        processBA.runHook("onpause", this, null);
	}

	@Override
	public void onDestroy() {
        super.onDestroy();
		previousOne = null;
        processBA.runHook("ondestroy", this, null);
	}
    @Override 
	public void onResume() {
		super.onResume();
        mostCurrent = this;
        anywheresoftware.b4a.Msgbox.isDismissing = false;
        if (activityBA != null) { //will be null during activity create (which waits for AfterLayout).
        	ResumeMessage rm = new ResumeMessage(mostCurrent);
        	BA.handler.post(rm);
        }
        processBA.runHook("onresume", this, null);
	}
    private static class ResumeMessage implements Runnable {
    	private final WeakReference<Activity> activity;
    	public ResumeMessage(Activity activity) {
    		this.activity = new WeakReference<Activity>(activity);
    	}
		public void run() {
            mainscreen mc = mostCurrent;
			if (mc == null || mc != activity.get())
				return;
			processBA.setActivityPaused(false);
            BA.LogInfo("** Activity (mainscreen) Resume **");
            if (mc != mostCurrent)
                return;
		    processBA.raiseEvent(mc._activity, "activity_resume", (Object[])null);
		}
    }
	@Override
	protected void onActivityResult(int requestCode, int resultCode,
	      android.content.Intent data) {
		processBA.onActivityResult(requestCode, resultCode, data);
        processBA.runHook("onactivityresult", this, new Object[] {requestCode, resultCode});
	}
	private static void initializeGlobals() {
		processBA.raiseEvent2(null, true, "globals", false, (Object[])null);
	}
    public void onRequestPermissionsResult(int requestCode,
        String permissions[], int[] grantResults) {
        for (int i = 0;i < permissions.length;i++) {
            Object[] o = new Object[] {permissions[i], grantResults[i] == 0};
            processBA.raiseEventFromDifferentThread(null,null, 0, "activity_permissionresult", true, o);
        }
            
    }

public anywheresoftware.b4a.keywords.Common __c = null;
public static anywheresoftware.b4a.objects.Serial _serial1 = null;
public static anywheresoftware.b4a.randomaccessfile.AsyncStreams _astream = null;
public static anywheresoftware.b4a.objects.collections.List _devicelist = null;
public static String _bufferstring = "";
public anywheresoftware.b4a.objects.drawable.BitmapDrawable _bmp = null;
public anywheresoftware.b4a.objects.PanelWrapper _panel1 = null;
public anywheresoftware.b4a.objects.ButtonWrapper _button2 = null;
public anywheresoftware.b4a.objects.ButtonWrapper _close = null;
public anywheresoftware.b4a.objects.ListViewWrapper _lstdevices = null;
public anywheresoftware.b4a.objects.ButtonWrapper _button1 = null;
public anywheresoftware.b4a.objects.ImageViewWrapper _imageview1 = null;
public anywheresoftware.b4a.objects.LabelWrapper _label6 = null;
public anywheresoftware.b4a.objects.LabelWrapper _label7 = null;
public anywheresoftware.b4a.objects.LabelWrapper _label8 = null;
public anywheresoftware.b4a.objects.LabelWrapper _label9 = null;
public anywheresoftware.b4a.objects.LabelWrapper _label11 = null;
public anywheresoftware.b4a.objects.LabelWrapper _label12 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext1 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext2 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext3 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext4 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext5 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext6 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext7 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext8 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext9 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext10 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext11 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext12 = null;
public anywheresoftware.b4a.objects.EditTextWrapper _edittext13 = null;
public anywheresoftware.b4a.objects.ButtonWrapper _button3 = null;
public anywheresoftware.b4a.objects.SpinnerWrapper _spinner1 = null;
public Abronic.Pavan.main _main = null;
public Abronic.Pavan.starter _starter = null;

public static void initializeProcessGlobals() {
             try {
                Class.forName(BA.applicationContext.getPackageName() + ".main").getMethod("initializeProcessGlobals").invoke(null, null);
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
}
public static String  _activity_create(boolean _firsttime) throws Exception{
anywheresoftware.b4a.objects.drawable.CanvasWrapper _khat1 = null;
 //BA.debugLineNum = 46;BA.debugLine="Sub Activity_Create(FirstTime As Boolean)";
 //BA.debugLineNum = 47;BA.debugLine="Activity.LoadLayout(\"MainScreen\")";
mostCurrent._activity.LoadLayout("MainScreen",mostCurrent.activityBA);
 //BA.debugLineNum = 48;BA.debugLine="Panel1.Visible = False";
mostCurrent._panel1.setVisible(anywheresoftware.b4a.keywords.Common.False);
 //BA.debugLineNum = 49;BA.debugLine="Serial1.Initialize(\"Serial1\")";
_serial1.Initialize("Serial1");
 //BA.debugLineNum = 50;BA.debugLine="DeviceList.Initialize";
_devicelist.Initialize();
 //BA.debugLineNum = 51;BA.debugLine="Spinner1.Add(\"سافت استارتر\")";
mostCurrent._spinner1.Add("سافت استارتر");
 //BA.debugLineNum = 52;BA.debugLine="Spinner1.Add(\"ست کنترل\")";
mostCurrent._spinner1.Add("ست کنترل");
 //BA.debugLineNum = 53;BA.debugLine="Spinner1.Add(\"دیمر دیجیتال\")";
mostCurrent._spinner1.Add("دیمر دیجیتال");
 //BA.debugLineNum = 54;BA.debugLine="Spinner1.SelectedIndex=1";
mostCurrent._spinner1.setSelectedIndex((int) (1));
 //BA.debugLineNum = 56;BA.debugLine="Dim khat1 As Canvas";
_khat1 = new anywheresoftware.b4a.objects.drawable.CanvasWrapper();
 //BA.debugLineNum = 57;BA.debugLine="khat1.Initialize(Activity)";
_khat1.Initialize((android.view.View)(mostCurrent._activity.getObject()));
 //BA.debugLineNum = 58;BA.debugLine="khat1.DrawLine(10%x,37%y,90%x,37%y,Colors.Blue,2d";
_khat1.DrawLine((float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (10),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (37),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (90),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (37),mostCurrent.activityBA)),anywheresoftware.b4a.keywords.Common.Colors.Blue,(float) (anywheresoftware.b4a.keywords.Common.DipToCurrent((int) (2))));
 //BA.debugLineNum = 59;BA.debugLine="khat1.DrawLine(10%x,44%y,90%x,44%y,Colors.Blue,2d";
_khat1.DrawLine((float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (10),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (44),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (90),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (44),mostCurrent.activityBA)),anywheresoftware.b4a.keywords.Common.Colors.Blue,(float) (anywheresoftware.b4a.keywords.Common.DipToCurrent((int) (2))));
 //BA.debugLineNum = 60;BA.debugLine="khat1.DrawLine(10%x,50%y,90%x,50%y,Colors.Blue,2d";
_khat1.DrawLine((float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (10),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (50),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (90),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (50),mostCurrent.activityBA)),anywheresoftware.b4a.keywords.Common.Colors.Blue,(float) (anywheresoftware.b4a.keywords.Common.DipToCurrent((int) (2))));
 //BA.debugLineNum = 61;BA.debugLine="khat1.DrawLine(10%x,58%y,90%x,58%y,Colors.Blue,2d";
_khat1.DrawLine((float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (10),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (58),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (90),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (58),mostCurrent.activityBA)),anywheresoftware.b4a.keywords.Common.Colors.Blue,(float) (anywheresoftware.b4a.keywords.Common.DipToCurrent((int) (2))));
 //BA.debugLineNum = 62;BA.debugLine="khat1.DrawLine(10%x,71%y,90%x,71%y,Colors.Blue,2d";
_khat1.DrawLine((float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (10),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (71),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (90),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (71),mostCurrent.activityBA)),anywheresoftware.b4a.keywords.Common.Colors.Blue,(float) (anywheresoftware.b4a.keywords.Common.DipToCurrent((int) (2))));
 //BA.debugLineNum = 63;BA.debugLine="khat1.DrawLine(10%x,77%y,90%x,77%y,Colors.Blue,2d";
_khat1.DrawLine((float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (10),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (77),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (90),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (77),mostCurrent.activityBA)),anywheresoftware.b4a.keywords.Common.Colors.Blue,(float) (anywheresoftware.b4a.keywords.Common.DipToCurrent((int) (2))));
 //BA.debugLineNum = 64;BA.debugLine="khat1.DrawLine(10%x,84%y,90%x,84%y,Colors.Blue,2d";
_khat1.DrawLine((float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (10),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (84),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerXToCurrent((float) (90),mostCurrent.activityBA)),(float) (anywheresoftware.b4a.keywords.Common.PerYToCurrent((float) (84),mostCurrent.activityBA)),anywheresoftware.b4a.keywords.Common.Colors.Blue,(float) (anywheresoftware.b4a.keywords.Common.DipToCurrent((int) (2))));
 //BA.debugLineNum = 66;BA.debugLine="End Sub";
return "";
}
public static String  _activity_pause(boolean _userclosed) throws Exception{
 //BA.debugLineNum = 72;BA.debugLine="Sub Activity_Pause (UserClosed As Boolean)";
 //BA.debugLineNum = 74;BA.debugLine="End Sub";
return "";
}
public static String  _activity_resume() throws Exception{
 //BA.debugLineNum = 68;BA.debugLine="Sub Activity_Resume";
 //BA.debugLineNum = 70;BA.debugLine="End Sub";
return "";
}
public static String  _astream_newdata(byte[] _buffer) throws Exception{
String _msg = "";
String[] _lines = null;
int _i = 0;
String _line = "";
 //BA.debugLineNum = 128;BA.debugLine="Sub AStream_NewData (Buffer() As Byte)";
 //BA.debugLineNum = 130;BA.debugLine="Dim msg As String = BytesToString(Buffer, 0, Buff";
_msg = anywheresoftware.b4a.keywords.Common.BytesToString(_buffer,(int) (0),_buffer.length,"UTF8");
 //BA.debugLineNum = 131;BA.debugLine="BufferString = BufferString & msg   ' تکه جدید رو";
mostCurrent._bufferstring = mostCurrent._bufferstring+_msg;
 //BA.debugLineNum = 133;BA.debugLine="If BufferString.Contains(Chr(10)) Then";
if (mostCurrent._bufferstring.contains(BA.ObjectToString(anywheresoftware.b4a.keywords.Common.Chr((int) (10))))) { 
 //BA.debugLineNum = 135;BA.debugLine="Dim lines() As String = Regex.Split(Chr(10), Buf";
_lines = anywheresoftware.b4a.keywords.Common.Regex.Split(BA.ObjectToString(anywheresoftware.b4a.keywords.Common.Chr((int) (10))),mostCurrent._bufferstring);
 //BA.debugLineNum = 136;BA.debugLine="For i = 0 To lines.Length - 1";
{
final int step5 = 1;
final int limit5 = (int) (_lines.length-1);
_i = (int) (0) ;
for (;_i <= limit5 ;_i = _i + step5 ) {
 //BA.debugLineNum = 137;BA.debugLine="Dim line As String = lines(i).Trim";
_line = _lines[_i].trim();
 //BA.debugLineNum = 138;BA.debugLine="If line.Length > 0 Then ParseEEPROMData(line)";
if (_line.length()>0) { 
_parseeepromdata(_line);};
 }
};
 //BA.debugLineNum = 140;BA.debugLine="BufferString = lines(lines.Length - 1)";
mostCurrent._bufferstring = _lines[(int) (_lines.length-1)];
 //BA.debugLineNum = 141;BA.debugLine="BufferString = \"\"";
mostCurrent._bufferstring = "";
 };
 //BA.debugLineNum = 143;BA.debugLine="End Sub";
return "";
}
public static String  _button1_click() throws Exception{
anywheresoftware.b4a.objects.collections.Map _paireddevices = null;
int _i = 0;
String _name = "";
String _mac = "";
 //BA.debugLineNum = 85;BA.debugLine="Private Sub Button1_Click";
 //BA.debugLineNum = 86;BA.debugLine="Panel1.Visible = True";
mostCurrent._panel1.setVisible(anywheresoftware.b4a.keywords.Common.True);
 //BA.debugLineNum = 87;BA.debugLine="If Serial1.IsEnabled = False Then";
if (_serial1.IsEnabled()==anywheresoftware.b4a.keywords.Common.False) { 
 //BA.debugLineNum = 88;BA.debugLine="ToastMessageShow(\"Bluetooth روشن نیست!\", True)";
anywheresoftware.b4a.keywords.Common.ToastMessageShow(BA.ObjectToCharSequence("Bluetooth روشن نیست!"),anywheresoftware.b4a.keywords.Common.True);
 //BA.debugLineNum = 89;BA.debugLine="Return";
if (true) return "";
 };
 //BA.debugLineNum = 92;BA.debugLine="Dim PairedDevices As Map";
_paireddevices = new anywheresoftware.b4a.objects.collections.Map();
 //BA.debugLineNum = 93;BA.debugLine="PairedDevices = Serial1.GetPairedDevices";
_paireddevices = _serial1.GetPairedDevices();
 //BA.debugLineNum = 94;BA.debugLine="lstDevices.Clear";
mostCurrent._lstdevices.Clear();
 //BA.debugLineNum = 96;BA.debugLine="For i = 0 To PairedDevices.Size - 1";
{
final int step9 = 1;
final int limit9 = (int) (_paireddevices.getSize()-1);
_i = (int) (0) ;
for (;_i <= limit9 ;_i = _i + step9 ) {
 //BA.debugLineNum = 97;BA.debugLine="Dim name As String = PairedDevices.GetKeyAt(i)";
_name = BA.ObjectToString(_paireddevices.GetKeyAt(_i));
 //BA.debugLineNum = 98;BA.debugLine="Dim mac As String = PairedDevices.GetValueAt(i)";
_mac = BA.ObjectToString(_paireddevices.GetValueAt(_i));
 //BA.debugLineNum = 99;BA.debugLine="lstDevices.AddSingleLine2(name, mac)";
mostCurrent._lstdevices.AddSingleLine2(BA.ObjectToCharSequence(_name),(Object)(_mac));
 }
};
 //BA.debugLineNum = 102;BA.debugLine="ToastMessageShow(\"لیست دستگاه‌ها آماده است\", Fals";
anywheresoftware.b4a.keywords.Common.ToastMessageShow(BA.ObjectToCharSequence("لیست دستگاه‌ها آماده است"),anywheresoftware.b4a.keywords.Common.False);
 //BA.debugLineNum = 103;BA.debugLine="End Sub";
return "";
}
public static String  _button2_click() throws Exception{
String _ss = "";
String _mode = "";
byte[] _data = null;
 //BA.debugLineNum = 201;BA.debugLine="Private Sub Button2_Click";
 //BA.debugLineNum = 202;BA.debugLine="Dim ss As String";
_ss = "";
 //BA.debugLineNum = 203;BA.debugLine="Dim mode As String";
_mode = "";
 //BA.debugLineNum = 204;BA.debugLine="If Spinner1.SelectedIndex = 0 Then mode = 0";
if (mostCurrent._spinner1.getSelectedIndex()==0) { 
_mode = BA.NumberToString(0);};
 //BA.debugLineNum = 205;BA.debugLine="If Spinner1.SelectedIndex = 1 Then mode = 1";
if (mostCurrent._spinner1.getSelectedIndex()==1) { 
_mode = BA.NumberToString(1);};
 //BA.debugLineNum = 206;BA.debugLine="If Spinner1.SelectedIndex = 2 Then mode = 2";
if (mostCurrent._spinner1.getSelectedIndex()==2) { 
_mode = BA.NumberToString(2);};
 //BA.debugLineNum = 207;BA.debugLine="ss= \"eeprom/\" & EditText1.Text & \"/\" & EditText2.";
_ss = "eeprom/"+mostCurrent._edittext1.getText()+"/"+mostCurrent._edittext2.getText()+"/"+mostCurrent._edittext3.getText()+"/"+mostCurrent._edittext4.getText()+"/"+mostCurrent._edittext5.getText()+"/"+mostCurrent._edittext6.getText()+"/"+mostCurrent._edittext7.getText()+"/"+BA.NumberToString(((double)(Double.parseDouble(mostCurrent._edittext8.getText()))*10))+"/"+BA.NumberToString(((double)(Double.parseDouble(mostCurrent._edittext9.getText()))*10))+"/"+BA.NumberToString(((double)(Double.parseDouble(mostCurrent._edittext10.getText()))*10))+"/"+mostCurrent._edittext11.getText()+"/"+mostCurrent._edittext12.getText()+"/"+_mode+BA.ObjectToString(anywheresoftware.b4a.keywords.Common.Chr((int) (13)))+BA.ObjectToString(anywheresoftware.b4a.keywords.Common.Chr((int) (10)));
 //BA.debugLineNum = 208;BA.debugLine="Dim data() As Byte = ss.GetBytes(\"UTF8\")'txtData.";
_data = _ss.getBytes("UTF8");
 //BA.debugLineNum = 209;BA.debugLine="AStream.Write(data)";
_astream.Write(_data);
 //BA.debugLineNum = 210;BA.debugLine="ToastMessageShow(ss , True)";
anywheresoftware.b4a.keywords.Common.ToastMessageShow(BA.ObjectToCharSequence(_ss),anywheresoftware.b4a.keywords.Common.True);
 //BA.debugLineNum = 211;BA.debugLine="End Sub";
return "";
}
public static String  _button3_click() throws Exception{
String _ss = "";
byte[] _data = null;
 //BA.debugLineNum = 193;BA.debugLine="Sub Button3_Click";
 //BA.debugLineNum = 194;BA.debugLine="Dim ss As String";
_ss = "";
 //BA.debugLineNum = 195;BA.debugLine="ss= \"ResetDevice\" & Chr(13) & Chr(10)";
_ss = "ResetDevice"+BA.ObjectToString(anywheresoftware.b4a.keywords.Common.Chr((int) (13)))+BA.ObjectToString(anywheresoftware.b4a.keywords.Common.Chr((int) (10)));
 //BA.debugLineNum = 196;BA.debugLine="Dim data() As Byte = ss.GetBytes(\"UTF8\")'txtData.";
_data = _ss.getBytes("UTF8");
 //BA.debugLineNum = 197;BA.debugLine="AStream.Write(data)";
_astream.Write(_data);
 //BA.debugLineNum = 198;BA.debugLine="End Sub";
return "";
}
public static String  _close_click() throws Exception{
 //BA.debugLineNum = 79;BA.debugLine="Private Sub Close_Click";
 //BA.debugLineNum = 80;BA.debugLine="Panel1.Visible = False";
mostCurrent._panel1.setVisible(anywheresoftware.b4a.keywords.Common.False);
 //BA.debugLineNum = 81;BA.debugLine="End Sub";
return "";
}
public static String  _globals() throws Exception{
 //BA.debugLineNum = 13;BA.debugLine="Sub Globals";
 //BA.debugLineNum = 14;BA.debugLine="Dim BufferString As String = \"\"   ' <--";
mostCurrent._bufferstring = "";
 //BA.debugLineNum = 15;BA.debugLine="Dim bmp As BitmapDrawable";
mostCurrent._bmp = new anywheresoftware.b4a.objects.drawable.BitmapDrawable();
 //BA.debugLineNum = 17;BA.debugLine="Private Panel1 As Panel";
mostCurrent._panel1 = new anywheresoftware.b4a.objects.PanelWrapper();
 //BA.debugLineNum = 18;BA.debugLine="Private Button2 As Button";
mostCurrent._button2 = new anywheresoftware.b4a.objects.ButtonWrapper();
 //BA.debugLineNum = 19;BA.debugLine="Private Close As Button";
mostCurrent._close = new anywheresoftware.b4a.objects.ButtonWrapper();
 //BA.debugLineNum = 20;BA.debugLine="Private lstDevices As ListView";
mostCurrent._lstdevices = new anywheresoftware.b4a.objects.ListViewWrapper();
 //BA.debugLineNum = 21;BA.debugLine="Private Button1 As Button";
mostCurrent._button1 = new anywheresoftware.b4a.objects.ButtonWrapper();
 //BA.debugLineNum = 22;BA.debugLine="Private ImageView1 As ImageView";
mostCurrent._imageview1 = new anywheresoftware.b4a.objects.ImageViewWrapper();
 //BA.debugLineNum = 23;BA.debugLine="Private Label6 As Label";
mostCurrent._label6 = new anywheresoftware.b4a.objects.LabelWrapper();
 //BA.debugLineNum = 24;BA.debugLine="Private Label7 As Label";
mostCurrent._label7 = new anywheresoftware.b4a.objects.LabelWrapper();
 //BA.debugLineNum = 25;BA.debugLine="Private Label8 As Label";
mostCurrent._label8 = new anywheresoftware.b4a.objects.LabelWrapper();
 //BA.debugLineNum = 26;BA.debugLine="Private Label9 As Label";
mostCurrent._label9 = new anywheresoftware.b4a.objects.LabelWrapper();
 //BA.debugLineNum = 27;BA.debugLine="Private Label11 As Label";
mostCurrent._label11 = new anywheresoftware.b4a.objects.LabelWrapper();
 //BA.debugLineNum = 28;BA.debugLine="Private Label12 As Label";
mostCurrent._label12 = new anywheresoftware.b4a.objects.LabelWrapper();
 //BA.debugLineNum = 29;BA.debugLine="Private EditText1 As EditText";
mostCurrent._edittext1 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 30;BA.debugLine="Private EditText2 As EditText";
mostCurrent._edittext2 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 31;BA.debugLine="Private EditText3 As EditText";
mostCurrent._edittext3 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 32;BA.debugLine="Private EditText4 As EditText";
mostCurrent._edittext4 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 33;BA.debugLine="Private EditText5 As EditText";
mostCurrent._edittext5 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 34;BA.debugLine="Private EditText6 As EditText";
mostCurrent._edittext6 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 35;BA.debugLine="Private EditText7 As EditText";
mostCurrent._edittext7 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 36;BA.debugLine="Private EditText8 As EditText";
mostCurrent._edittext8 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 37;BA.debugLine="Private EditText9 As EditText";
mostCurrent._edittext9 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 38;BA.debugLine="Private EditText10 As EditText";
mostCurrent._edittext10 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 39;BA.debugLine="Private EditText11 As EditText";
mostCurrent._edittext11 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 40;BA.debugLine="Private EditText12 As EditText";
mostCurrent._edittext12 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 41;BA.debugLine="Private EditText13 As EditText";
mostCurrent._edittext13 = new anywheresoftware.b4a.objects.EditTextWrapper();
 //BA.debugLineNum = 42;BA.debugLine="Private Button3 As Button";
mostCurrent._button3 = new anywheresoftware.b4a.objects.ButtonWrapper();
 //BA.debugLineNum = 43;BA.debugLine="Private Spinner1 As Spinner";
mostCurrent._spinner1 = new anywheresoftware.b4a.objects.SpinnerWrapper();
 //BA.debugLineNum = 44;BA.debugLine="End Sub";
return "";
}
public static String  _lstdevices_itemclick(int _position,Object _value) throws Exception{
String _macaddress = "";
 //BA.debugLineNum = 105;BA.debugLine="Sub lstDevices_ItemClick (Position As Int, Value A";
 //BA.debugLineNum = 106;BA.debugLine="Dim MacAddress As String = Value";
_macaddress = BA.ObjectToString(_value);
 //BA.debugLineNum = 107;BA.debugLine="Serial1.Connect(MacAddress)   ' اتصال به ماژول ان";
_serial1.Connect(processBA,_macaddress);
 //BA.debugLineNum = 108;BA.debugLine="ToastMessageShow(\"در حال اتصال...\", False)";
anywheresoftware.b4a.keywords.Common.ToastMessageShow(BA.ObjectToCharSequence("در حال اتصال..."),anywheresoftware.b4a.keywords.Common.False);
 //BA.debugLineNum = 109;BA.debugLine="End Sub";
return "";
}
public static String  _parseeepromdata(String _data) throws Exception{
String[] _parts = null;
 //BA.debugLineNum = 145;BA.debugLine="Sub ParseEEPROMData(Data As String)";
 //BA.debugLineNum = 147;BA.debugLine="If Data.StartsWith(\"eeprom/\") = True Then";
if (_data.startsWith("eeprom/")==anywheresoftware.b4a.keywords.Common.True) { 
 //BA.debugLineNum = 148;BA.debugLine="Dim parts() As String = Regex.Split(\"/\", Data)";
_parts = anywheresoftware.b4a.keywords.Common.Regex.Split("/",_data);
 //BA.debugLineNum = 149;BA.debugLine="If parts.Length == 14 Then";
if (_parts.length==14) { 
 //BA.debugLineNum = 150;BA.debugLine="EditText1.Text = parts(1)";
mostCurrent._edittext1.setText(BA.ObjectToCharSequence(_parts[(int) (1)]));
 //BA.debugLineNum = 151;BA.debugLine="EditText2.Text = parts(2)";
mostCurrent._edittext2.setText(BA.ObjectToCharSequence(_parts[(int) (2)]));
 //BA.debugLineNum = 152;BA.debugLine="EditText3.Text = parts(3)";
mostCurrent._edittext3.setText(BA.ObjectToCharSequence(_parts[(int) (3)]));
 //BA.debugLineNum = 153;BA.debugLine="EditText4.Text = parts(4)";
mostCurrent._edittext4.setText(BA.ObjectToCharSequence(_parts[(int) (4)]));
 //BA.debugLineNum = 154;BA.debugLine="EditText5.Text = parts(5)";
mostCurrent._edittext5.setText(BA.ObjectToCharSequence(_parts[(int) (5)]));
 //BA.debugLineNum = 155;BA.debugLine="EditText6.Text = parts(6)";
mostCurrent._edittext6.setText(BA.ObjectToCharSequence(_parts[(int) (6)]));
 //BA.debugLineNum = 156;BA.debugLine="EditText7.Text = parts(7)";
mostCurrent._edittext7.setText(BA.ObjectToCharSequence(_parts[(int) (7)]));
 //BA.debugLineNum = 157;BA.debugLine="EditText8.Text = parts(8) / 10";
mostCurrent._edittext8.setText(BA.ObjectToCharSequence((double)(Double.parseDouble(_parts[(int) (8)]))/(double)10));
 //BA.debugLineNum = 158;BA.debugLine="EditText9.Text = parts(9) / 10";
mostCurrent._edittext9.setText(BA.ObjectToCharSequence((double)(Double.parseDouble(_parts[(int) (9)]))/(double)10));
 //BA.debugLineNum = 159;BA.debugLine="EditText10.Text = parts(10) / 10";
mostCurrent._edittext10.setText(BA.ObjectToCharSequence((double)(Double.parseDouble(_parts[(int) (10)]))/(double)10));
 //BA.debugLineNum = 160;BA.debugLine="EditText11.Text = parts(11)";
mostCurrent._edittext11.setText(BA.ObjectToCharSequence(_parts[(int) (11)]));
 //BA.debugLineNum = 161;BA.debugLine="EditText12.Text = parts(12)";
mostCurrent._edittext12.setText(BA.ObjectToCharSequence(_parts[(int) (12)]));
 //BA.debugLineNum = 162;BA.debugLine="EditText13.Text = parts(13)";
mostCurrent._edittext13.setText(BA.ObjectToCharSequence(_parts[(int) (13)]));
 //BA.debugLineNum = 163;BA.debugLine="If parts(13) = 0 Then Spinner1.SelectedIndex =";
if ((_parts[(int) (13)]).equals(BA.NumberToString(0))) { 
mostCurrent._spinner1.setSelectedIndex((int) (0));};
 //BA.debugLineNum = 164;BA.debugLine="If parts(13) = 1 Then Spinner1.SelectedIndex =";
if ((_parts[(int) (13)]).equals(BA.NumberToString(1))) { 
mostCurrent._spinner1.setSelectedIndex((int) (1));};
 //BA.debugLineNum = 165;BA.debugLine="If parts(13) = 2 Then Spinner1.SelectedIndex =";
if ((_parts[(int) (13)]).equals(BA.NumberToString(2))) { 
mostCurrent._spinner1.setSelectedIndex((int) (2));};
 };
 };
 //BA.debugLineNum = 170;BA.debugLine="If Data.StartsWith(\"value/\") = True Then";
if (_data.startsWith("value/")==anywheresoftware.b4a.keywords.Common.True) { 
 //BA.debugLineNum = 171;BA.debugLine="Dim parts() As String = Regex.Split(\"/\", Data)";
_parts = anywheresoftware.b4a.keywords.Common.Regex.Split("/",_data);
 //BA.debugLineNum = 172;BA.debugLine="If parts.Length == 6 Then";
if (_parts.length==6) { 
 //BA.debugLineNum = 173;BA.debugLine="Label6.Text = parts(1) ' ولتاژ پمپ";
mostCurrent._label6.setText(BA.ObjectToCharSequence(_parts[(int) (1)]));
 //BA.debugLineNum = 174;BA.debugLine="Label7.Text = parts(2) ' جریان پمپ";
mostCurrent._label7.setText(BA.ObjectToCharSequence(_parts[(int) (2)]));
 //BA.debugLineNum = 175;BA.debugLine="Label8.Text = parts(3)  ' فشار پمپ";
mostCurrent._label8.setText(BA.ObjectToCharSequence(_parts[(int) (3)]));
 //BA.debugLineNum = 176;BA.debugLine="If parts(4) = 1 Then Label9.Text = \"روشن\"";
if ((_parts[(int) (4)]).equals(BA.NumberToString(1))) { 
mostCurrent._label9.setText(BA.ObjectToCharSequence("روشن"));};
 //BA.debugLineNum = 177;BA.debugLine="If parts(4) = 0 Then Label9.Text = \"خاموش\"";
if ((_parts[(int) (4)]).equals(BA.NumberToString(0))) { 
mostCurrent._label9.setText(BA.ObjectToCharSequence("خاموش"));};
 //BA.debugLineNum = 179;BA.debugLine="If parts(5) = 0 Then";
if ((_parts[(int) (5)]).equals(BA.NumberToString(0))) { 
 //BA.debugLineNum = 180;BA.debugLine="Label11.Text = \"عادی\"";
mostCurrent._label11.setText(BA.ObjectToCharSequence("عادی"));
 //BA.debugLineNum = 181;BA.debugLine="Label12.Text = \"\"";
mostCurrent._label12.setText(BA.ObjectToCharSequence(""));
 };
 //BA.debugLineNum = 183;BA.debugLine="If parts(5) >= 1 Then";
if ((double)(Double.parseDouble(_parts[(int) (5)]))>=1) { 
 //BA.debugLineNum = 184;BA.debugLine="Label11.Text = \"مشکل\"";
mostCurrent._label11.setText(BA.ObjectToCharSequence("مشکل"));
 //BA.debugLineNum = 185;BA.debugLine="Label12.Text = \"هواکشی پمپ\"";
mostCurrent._label12.setText(BA.ObjectToCharSequence("هواکشی پمپ"));
 };
 };
 };
 //BA.debugLineNum = 190;BA.debugLine="End Sub";
return "";
}
public static String  _process_globals() throws Exception{
 //BA.debugLineNum = 6;BA.debugLine="Sub Process_Globals";
 //BA.debugLineNum = 7;BA.debugLine="Dim Serial1 As Serial";
_serial1 = new anywheresoftware.b4a.objects.Serial();
 //BA.debugLineNum = 8;BA.debugLine="Dim AStream As AsyncStreams";
_astream = new anywheresoftware.b4a.randomaccessfile.AsyncStreams();
 //BA.debugLineNum = 9;BA.debugLine="Dim DeviceList As List";
_devicelist = new anywheresoftware.b4a.objects.collections.List();
 //BA.debugLineNum = 11;BA.debugLine="End Sub";
return "";
}
public static String  _serial1_connected(boolean _success) throws Exception{
String _ss = "";
byte[] _data = null;
 //BA.debugLineNum = 111;BA.debugLine="Sub Serial1_Connected (Success As Boolean)";
 //BA.debugLineNum = 112;BA.debugLine="If Success Then";
if (_success) { 
 //BA.debugLineNum = 113;BA.debugLine="ToastMessageShow(\"اتصال موفق!\", False)";
anywheresoftware.b4a.keywords.Common.ToastMessageShow(BA.ObjectToCharSequence("اتصال موفق!"),anywheresoftware.b4a.keywords.Common.False);
 //BA.debugLineNum = 114;BA.debugLine="AStream.Initialize(Serial1.InputStream, Serial1.";
_astream.Initialize(processBA,_serial1.getInputStream(),_serial1.getOutputStream(),"AStream");
 //BA.debugLineNum = 115;BA.debugLine="bmp.Initialize(LoadBitmap(File.DirAssets, \"conne";
mostCurrent._bmp.Initialize((android.graphics.Bitmap)(anywheresoftware.b4a.keywords.Common.LoadBitmap(anywheresoftware.b4a.keywords.Common.File.getDirAssets(),"connected_500px.png").getObject()));
 //BA.debugLineNum = 116;BA.debugLine="ImageView1.Background = bmp";
mostCurrent._imageview1.setBackground((android.graphics.drawable.Drawable)(mostCurrent._bmp.getObject()));
 //BA.debugLineNum = 117;BA.debugLine="Dim ss As String";
_ss = "";
 //BA.debugLineNum = 118;BA.debugLine="ss= \"GetEeprom\" & Chr(13) & Chr(10)";
_ss = "GetEeprom"+BA.ObjectToString(anywheresoftware.b4a.keywords.Common.Chr((int) (13)))+BA.ObjectToString(anywheresoftware.b4a.keywords.Common.Chr((int) (10)));
 //BA.debugLineNum = 119;BA.debugLine="Dim data() As Byte = ss.GetBytes(\"UTF8\")'txtData";
_data = _ss.getBytes("UTF8");
 //BA.debugLineNum = 120;BA.debugLine="AStream.Write(data)";
_astream.Write(_data);
 //BA.debugLineNum = 121;BA.debugLine="Panel1.Visible = False";
mostCurrent._panel1.setVisible(anywheresoftware.b4a.keywords.Common.False);
 //BA.debugLineNum = 122;BA.debugLine="Button1.Text = \"متصل شد\"";
mostCurrent._button1.setText(BA.ObjectToCharSequence("متصل شد"));
 }else {
 //BA.debugLineNum = 124;BA.debugLine="ToastMessageShow(\"اتصال ناموفق!\", True)";
anywheresoftware.b4a.keywords.Common.ToastMessageShow(BA.ObjectToCharSequence("اتصال ناموفق!"),anywheresoftware.b4a.keywords.Common.True);
 };
 //BA.debugLineNum = 126;BA.debugLine="End Sub";
return "";
}
}
