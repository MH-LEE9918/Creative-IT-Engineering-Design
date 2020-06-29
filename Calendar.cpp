#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int year, month, week;
void input(); // 연도와 월을 입력받는 함수. 
int getweek(int year, int month);
void Cal_leap(); // 윤년계산 
void output_calendar(); // 입력받은 연도와 월의 달력을 출력  
void Select_Option(int&); // 옵션을 출력하고 입력받음 
void textcolor(int foreground, int background); //색깔추가기능 
void gotoxy(int x, int y);

class MEMO {
private:
    string DATE;   
    string schedule;  
public:
    int putSchedule();   
    void printSchedule(); 
};

int MEMO::putSchedule() {
    cout << "일정 추가할 날짜: ";
    getline(cin, DATE);
    cout << endl;
    cout << "일정 내용: ";
    getline(cin, schedule);
    cout << endl;
    return 0;
}

void MEMO::printSchedule() {
    cout << endl << endl;
    cout << DATE << endl;
    cout << schedule << endl;
    cout << endl << endl;
}

int main()
{
    input();
    week = getweek(year, month);
    Cal_leap();
    output_calendar();
    int option_num = 0;
    Select_Option(option_num);
    return 0;
}

void input() {
    printf("년: ");
    cin >> year;
    printf("월: ");
    cin >> month;
}

int getweek(int year, int month) {
    int week = year + (year / 4 - year / 100 + year / 400);

    for (int i = 0; i < month - 1; i++)
        week += Month_days[i];

    return (week % 7);
}

void Cal_leap() {
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        Month_days[1]++;
}

void output_calendar() {
	textcolor(15, 0);
	cout << "  " << endl << "      [" << year << "년 " << month << "월]      " << endl << endl << "  " <<
        "일 " << "월 " << "화 " << "수 " << "목 " << "금 " << "토  " << endl << "  ____________________" << endl << "  ";
	textcolor(15, 0);
	
    for (int i = 0; i < week; i++)
        cout << "   ";
	
    for (int j = 1; j <= Month_days[month - 1]; j++)
    {
    	if(week % 7 == 0) textcolor(12, 0); // 12(빨) , 9(파) 
    	else if(week % 7 == 6) textcolor(9, 0);
    	else textcolor(15, 0);
        printf("%2d ", j);
        if (week % 7 == 6)
            cout << "  " << endl << "  "; 
        week = (week + 1) % 7;
    }
    cout << endl;
}

void Select_Option(int &num) {	
    gotoxy(59, 2);
	cout << "[원하는 옵션 선택]";
	gotoxy(60, 3);
	cout << "① 일정 추가" ;
    gotoxy(60, 4);
	cout << "② 일정 수정" ;
    gotoxy(60, 5);
	cout << "③ 일정 삭제" ;
    gotoxy(60, 6);
	cout << "④ 음력 변환" ;
    gotoxy(60, 7);
	cout << "⑤ 날짜 계산" ;
    gotoxy(60, 8);
	cout << "⑥ 전체 일정 확인" ;
    gotoxy(60, 9);
	cout << "⑦ 날짜 변경" ;
    gotoxy(60, 10);
	cout << "⑧ 종료" ;
    gotoxy(60, 11);
	cout << "옵션 변호: ";
    cin >> num;
    if (num == 1){
    	cout << endl;
    	MEMO obj;
    	cout << endl;
    	obj.putSchedule();
    	Select_Option(num);
	}
    if (num == 7) {
        system("cls");
        input();
        week = getweek(year, month);
        Cal_leap();
        output_calendar();
        Select_Option(num);  
	}
    else if (num == 8)
	{
		system("cls");
		cout << "\n프로그램을 종료합니다." << endl;
		Sleep(1000);	
	}
    else {
    	cout << "\n\n*************다시 선택해주세요.*************" << endl;
        while(num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6 && num != 7 && num != 8)  
            Select_Option(num);
    }
}

void textcolor(int foreground, int background) {
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x,int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}
