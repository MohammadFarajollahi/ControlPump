//char str_cut[100];
//
//void substring(char string[200], int x, int y)
//{
//  memcpy(str_cut, "", sizeof(1));
//  int l = y - x;
//  char sub_str[50];
//  for (int i = 0; i < l; i++)
//  {
//    sub_str[i] = string[x + i];
//  }
//  sub_str[l] = '\0';
//  sprintf(str_cut, sub_str);
//}

int s[13];  // s1 تا s13

void ParseData(char *data)
{
  // بررسی اینکه دیتا با "eeprom/" شروع میشه
  if (strncmp(data, "eeprom/", 7) != 0)
    return; // رشته معتبر نیست
  
  // اشاره‌گر به بعد از "eeprom/"
  char *token = strtok(data + 7, "/");
  int i = 0;
  
  while (token != NULL && i < 13)
  {
    s[i] = atoi(token); // تبدیل رشته به عدد
    token = strtok(NULL, "/");
    i++;
  }
}

void check(){
  
  
  if (strstr(char_test1, "GetEeprom") != NULL){
    HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
    HAL_Delay(200);
    HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
    strcpy(ss , "eeprom/");
    char ch[100];
    Current_eeprom *= 10;
    UpCurrent_eeprom *= 10;
    DownCurrent_eeprom *=10;
    CurrentDownRealizeTime_eeprom/=60;
    int cu1 = (int)Current_eeprom;
    int cu2 = (int)UpCurrent_eeprom;
    int cu3 = (int)DownCurrent_eeprom;
    sprintf(ch, "%d/%d/%d/%d/%d/%d/%d/%d/%d/%d/%d/%d/%d/",StartVoltage_eeprom,StartTime_eeprom,SoftTime_eeprom,pressure_eeprom,PressureDown_eeprom,ofTimer_eeprom,TurnOnDelay_eeprom,cu1,cu2,cu3,TimeHavaKeshi_eeprom,CurrentDownRealizeTime_eeprom,mode_eeprom);
    strcat(ss,ch);
    show_uart(ss);
    Current_eeprom/=10;
    UpCurrent_eeprom /=10;
    DownCurrent_eeprom/=10;
    CurrentDownRealizeTime_eeprom*=60;
  }
  
  if (strstr(char_test1, "eeprom") != NULL){ //eeprom/
  
    ParseData(char_test1);
    if(s[3] > s[4] && s[8] > s[9]){
        HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
    HAL_Delay(100);
    HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
    HAL_Delay(150);
    HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
    HAL_Delay(250);
    HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      StartVoltage_eeprom = s[0];
      HAL_Delay(5);
      StartTime_eeprom = s[1];
      HAL_Delay(5);
      SoftTime_eeprom = s[2];
      HAL_Delay(5);
      pressure_eeprom = s[3];
      HAL_Delay(5);
      PressureDown_eeprom = s[4];
      HAL_Delay(5);
      ofTimer_eeprom = s[5];
      HAL_Delay(5);
      TurnOnDelay_eeprom = s[6];
      HAL_Delay(5);
      Current_eeprom = s[7];
      Current_eeprom /= 10;
      HAL_Delay(5);
      UpCurrent_eeprom = s[8];
      UpCurrent_eeprom /=10;
      HAL_Delay(5);
      DownCurrent_eeprom = s[9];
      DownCurrent_eeprom /=10;
      HAL_Delay(5);
      TimeHavaKeshi_eeprom = s[10];
      HAL_Delay(5);
      CurrentDownRealizeTime_eeprom = s[11];
      HAL_Delay(5); 
      mode_eeprom = s[12];
      HAL_Delay(5);
      
      eeprom_write_int16(s[0],0);
      HAL_Delay(5);
      eeprom_write_int16(s[1],10);
      HAL_Delay(5);
      eeprom_write_int16(s[2],20);
      HAL_Delay(5);
      eeprom_write_int16(s[3],30);
      HAL_Delay(5);
      eeprom_write_int16(s[12],40);
      HAL_Delay(5);
      eeprom_write_int16(s[7],50);
      HAL_Delay(5);
      eeprom_write_int16(s[6],60);
      HAL_Delay(5);
      eeprom_write_int16(s[4],70);
      HAL_Delay(5);
      eeprom_write_int16(s[5],80);
      HAL_Delay(5);
      eeprom_write_int16(s[8],90);
      HAL_Delay(5);
      eeprom_write_int16(s[9],100);
      HAL_Delay(5);
      eeprom_write_int16(s[10],110);
      HAL_Delay(5);
      eeprom_write_int16(s[11],120);
      HAL_Delay(5); 
      Lcd_Clear();
      Lcd_Refresh();
      sprintf(ss , "Saved");
      lcd_putsf_point(0,0,ss,TAHOMA_8x10);
      Lcd_Refresh();
      HAL_Delay(1500);
      hang = 1;
      HAL_Delay(500);
    }else{
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_SET);
      HAL_Delay(50);
      HAL_GPIO_WritePin(buzzer_GPIO_Port, buzzer_Pin, GPIO_PIN_RESET);
      HAL_Delay(50);
      show_uart("Fualt");
    }
    
  }
  
  if (strstr(char_test1, "ResetDevice") != NULL){ //eeprom/
    hang = 1;
    HAL_Delay(500);
  }
  
  
}