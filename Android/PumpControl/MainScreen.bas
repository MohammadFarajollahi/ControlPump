B4A=true
Group=Default Group
ModulesStructureVersion=1
Type=Activity
Version=13.1
@EndOfDesignText@
#Region  Activity Attributes 
	#FullScreen: False
	#IncludeTitle: false
#End Region

Sub Process_Globals
	Dim Serial1 As Serial
	Dim AStream As AsyncStreams
	Dim DeviceList As List

End Sub

Sub Globals
	Dim BufferString As String = ""   ' <--
	Dim bmp As BitmapDrawable

	Private Panel1 As Panel
	Private Button2 As Button
	Private Close As Button
	Private lstDevices As ListView
	Private Button1 As Button
	Private ImageView1 As ImageView
	Private Label6 As Label
	Private Label7 As Label
	Private Label8 As Label
	Private Label9 As Label
	Private Label11 As Label
	Private Label12 As Label
	Private EditText1 As EditText
	Private EditText2 As EditText
	Private EditText3 As EditText
	Private EditText4 As EditText
	Private EditText5 As EditText
	Private EditText6 As EditText
	Private EditText7 As EditText
	Private EditText8 As EditText
	Private EditText9 As EditText
	Private EditText10 As EditText
	Private EditText11 As EditText
	Private EditText12 As EditText
	Private EditText13 As EditText
	Private Button3 As Button
	Private Spinner1 As Spinner
End Sub

Sub Activity_Create(FirstTime As Boolean)
	Activity.LoadLayout("MainScreen")
	Panel1.Visible = False
	Serial1.Initialize("Serial1")
	DeviceList.Initialize
	Spinner1.Add("سافت استارتر")
	Spinner1.Add("ست کنترل")
	Spinner1.Add("دیمر دیجیتال")
	Spinner1.SelectedIndex=1
	
	Dim khat1 As Canvas
	khat1.Initialize(Activity)
	khat1.DrawLine(10%x,37%y,90%x,37%y,Colors.Blue,2dip)
	khat1.DrawLine(10%x,44%y,90%x,44%y,Colors.Blue,2dip)
	khat1.DrawLine(10%x,50%y,90%x,50%y,Colors.Blue,2dip)
	khat1.DrawLine(10%x,58%y,90%x,58%y,Colors.Blue,2dip)
	khat1.DrawLine(10%x,71%y,90%x,71%y,Colors.Blue,2dip)
	khat1.DrawLine(10%x,77%y,90%x,77%y,Colors.Blue,2dip)
	khat1.DrawLine(10%x,84%y,90%x,84%y,Colors.Blue,2dip)
	
End Sub

Sub Activity_Resume

End Sub

Sub Activity_Pause (UserClosed As Boolean)

End Sub




Private Sub Close_Click
	Panel1.Visible = False
End Sub


'اتصال به بلوتوث
Private Sub Button1_Click
	Panel1.Visible = True
	If Serial1.IsEnabled = False Then
		ToastMessageShow("Bluetooth روشن نیست!", True)
		Return
	End If
    
	Dim PairedDevices As Map
	PairedDevices = Serial1.GetPairedDevices
	lstDevices.Clear
    
	For i = 0 To PairedDevices.Size - 1
		Dim name As String = PairedDevices.GetKeyAt(i)
		Dim mac As String = PairedDevices.GetValueAt(i)
		lstDevices.AddSingleLine2(name, mac)
	Next
    
	ToastMessageShow("لیست دستگاه‌ها آماده است", False)
End Sub

Sub lstDevices_ItemClick (Position As Int, Value As Object)
	Dim MacAddress As String = Value
	Serial1.Connect(MacAddress)   ' اتصال به ماژول انتخاب شده
	ToastMessageShow("در حال اتصال...", False)
End Sub

Sub Serial1_Connected (Success As Boolean)
	If Success Then
		ToastMessageShow("اتصال موفق!", False)
		AStream.Initialize(Serial1.InputStream, Serial1.OutputStream, "AStream")
		bmp.Initialize(LoadBitmap(File.DirAssets, "connected_500px.png"))
		ImageView1.Background = bmp
		Dim ss As String
		ss= "GetEeprom" & Chr(13) & Chr(10)
		Dim data() As Byte = ss.GetBytes("UTF8")'txtData.Text.GetBytes("UTF8")
		AStream.Write(data)
		Panel1.Visible = False
		Button1.Text = "متصل شد"
	Else
		ToastMessageShow("اتصال ناموفق!", True)
	End If
End Sub

Sub AStream_NewData (Buffer() As Byte)
	
	Dim msg As String = BytesToString(Buffer, 0, Buffer.Length, "UTF8")
	BufferString = BufferString & msg   ' تکه جدید رو به بافر اضافه کن
	
	If BufferString.Contains(Chr(10)) Then
	'	EditText14.Text =BufferString
		Dim lines() As String = Regex.Split(Chr(10), BufferString)
		For i = 0 To lines.Length - 1
			Dim line As String = lines(i).Trim
		If line.Length > 0 Then ParseEEPROMData(line)
		Next
		BufferString = lines(lines.Length - 1)
		BufferString = ""
	End If
	End Sub

Sub ParseEEPROMData(Data As String)
	'EditText14.Text = Data
	If Data.StartsWith("eeprom/") = True Then
		Dim parts() As String = Regex.Split("/", Data)
		If parts.Length == 14 Then
			EditText1.Text = parts(1)
			EditText2.Text = parts(2)
			EditText3.Text = parts(3)
			EditText4.Text = parts(4)
			EditText5.Text = parts(5)
			EditText6.Text = parts(6)
			EditText7.Text = parts(7)
			EditText8.Text = parts(8) / 10
			EditText9.Text = parts(9) / 10
			EditText10.Text = parts(10) / 10
			EditText11.Text = parts(11)
			EditText12.Text = parts(12)
			EditText13.Text = parts(13)
			If parts(13) = 0 Then Spinner1.SelectedIndex = 0
			If parts(13) = 1 Then Spinner1.SelectedIndex = 1
			If parts(13) = 2 Then Spinner1.SelectedIndex = 2
		
		End If
	End If
	
	If Data.StartsWith("value/") = True Then
		Dim parts() As String = Regex.Split("/", Data)
		If parts.Length == 6 Then
			Label6.Text = parts(1) ' ولتاژ پمپ
			Label7.Text = parts(2) ' جریان پمپ
			Label8.Text = parts(3)  ' فشار پمپ
			If parts(4) = 1 Then Label9.Text = "روشن"
			If parts(4) = 0 Then Label9.Text = "خاموش"
			
			If parts(5) = 0 Then
				 Label11.Text = "عادی"
				Label12.Text = ""
			End If
			If parts(5) >= 1 Then
				 Label11.Text = "مشکل"
				Label12.Text = "هواکشی پمپ"
			End If
			
		End If
	End If
End Sub


 Sub Button3_Click
	Dim ss As String
	ss= "ResetDevice" & Chr(13) & Chr(10)
	Dim data() As Byte = ss.GetBytes("UTF8")'txtData.Text.GetBytes("UTF8")
	AStream.Write(data)
End Sub


Private Sub Button2_Click
	Dim ss As String
	Dim mode As String
	If Spinner1.SelectedIndex = 0 Then mode = 0
	If Spinner1.SelectedIndex = 1 Then mode = 1
	If Spinner1.SelectedIndex = 2 Then mode = 2
	ss= "eeprom/" & EditText1.Text & "/" & EditText2.Text & "/" & EditText3.Text & "/" & EditText4.Text & "/" & EditText5.Text & "/" & EditText6.Text & "/" & EditText7.Text & "/" & (EditText8.Text * 10) & "/" & (EditText9.Text * 10) & "/" & (EditText10.Text * 10) & "/" & EditText11.Text & "/" & EditText12.Text & "/" & mode & Chr(13) & Chr(10)
	Dim data() As Byte = ss.GetBytes("UTF8")'txtData.Text.GetBytes("UTF8")
	AStream.Write(data)
	ToastMessageShow(ss , True)
End Sub





