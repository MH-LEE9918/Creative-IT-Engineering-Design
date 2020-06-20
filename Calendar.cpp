#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

int Month_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int year, month, week;

void input(); // ������ ���� �Է¹޴� �Լ�. 
int getweek(int year, int month);
void Cal_leap(); // ������ 
void output_calendar(); // �Է¹��� ������ ���� �޷��� ���  
void Select_Option(int&); // �ɼ��� ����ϰ� �Է¹��� 
void textcolor(int foreground, int background); //�����߰���� 

int main()
{
    input();
    week = getweek(year, month);
    Cal_leap();
    output_calendar();

    int option_num = 0;
    Select_Option(option_num);

    //�׽�Ʈ�뵵
    textcolor(11, 0);
    cout << "�׽�Ʈ�뵵 �Դϴ�" << endl;
    textcolor(7, 0);
    return 0;
}

void input() {
    printf("��: ");
    cin >> year;
    printf("��: ");
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
    cout << "  " << endl << "       " << year << "�� " << month << "��       " << endl << endl << "  " <<
        "�� " << "�� " << "ȭ " << "�� " << "�� " << "�� " << "��  " << endl << "  ";

    for (int i = 0; i < week; i++)
        cout << "   ";

    for (int j = 1; j <= Month_days[month - 1]; j++)
    {
        printf("%2d ", j);
        if (week % 7 == 6)
            cout << "  " << endl << "  ";
        week = (week + 1) % 7;
    }
    cout << endl;
}

void Select_Option(int &num) {
    cout << "\n\n" << "[���ϴ� �ɼ� ����]" << "\n" << endl;
    cout << "�� ���� �߰�" << endl;
    cout << "�� ���� ����" << endl;
    cout << "�� ���� ����" << endl;
    cout << "�� ���� ��ȯ" << endl;
    cout << "�� ��¥ ���" << endl;
    cout << "�� ��ü ���� Ȯ��" << endl;
    cout << "�� ��¥ ����" << endl;
    cout << "�� ����" << endl << endl;

    cout << "�ɼ� ��ȣ: ";
    cin >> num;
    
    if (num == 7) {
        cout << endl;
        input();
        week = getweek(year, month);
        Cal_leap();
        output_calendar();
        while(num != 8) Select_Option(num);  
	}
    else if (num == 8) cout << "\n���α׷��� �����մϴ�." << endl;
    else {
    	cout << "\n\n*************�ٽ� �������ּ���.*************" << endl;
        while(num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6 && num != 7 && num != 8)  
            Select_Option(num);
    }
}

void textcolor(int foreground, int background) {
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
