#include "StdAfx.h"
#include "Gradebook.h"


Gradebook::Gradebook() :Book()
{
	m_Kurs = 0;
	m_number = 0;
}

Gradebook::Gradebook(int UDK, char * avtor, char * title, char * edition, int year, int Kurs, int number) : Book(UDK, avtor, title, edition, year)
{
	m_Kurs = Kurs;
	m_number = number;
}
Gradebook::Gradebook(Gradebook & cSourse)
{
	m_Kurs = cSourse.m_Kurs;
	m_number = cSourse.m_number;
}

Gradebook:: ~Gradebook()
{

}

/*Set methods*/
void Gradebook::setKurs(int _Kurs)
{
	m_Kurs = _Kurs;
}

void Gradebook::SetUDK(int _number)
{
	m_number = _number;
}

/*Get methods*/
int  Gradebook::getKurs()
{
	return m_Kurs;
}

int Gradebook::GetUDK()
{
	return m_number;
}

int Gradebook::GetRatingsOfIndex(int index)
{
	map<string, int>::iterator p = RatingsOfSubjects.begin();
	for (int i = 0; i<index; i++) p++;
	return p->second;

}

string Gradebook::GetSubjectsOfIndex(int index)
{
	map<string, int>::iterator p = RatingsOfSubjects.begin();
	for (int i = 0; i<index; i++) p++;
	return p->first;
}
int Gradebook::GetRatingsOfSubject(string sub)
{
	map<string, int>::iterator p = RatingsOfSubjects.find(sub);
	return p->second;
}
int Gradebook::GetRatingsCount()
{
	return RatingsOfSubjects.size();
}
void Gradebook::AddRatingsOfSubject(string sub, int rat)
{
	RatingsOfSubjects.insert(pair<string, int>(sub, rat));
}
int Gradebook::SerBal() // ������� ���
{
	int serbal;
	for (auto it = RatingsOfSubjects.begin(); it != RatingsOfSubjects.end(); ++it)
		serbal += it->second;
	return RatingsOfSubjects.size()>0 ? serbal / RatingsOfSubjects.size() : 0;
}
int Gradebook::GetMinRating() // �������� ������
{
	map<string, int>::iterator it = RatingsOfSubjects.begin();
	int min = it->second;
	for (auto it = RatingsOfSubjects.begin(); it != RatingsOfSubjects.end(); ++it)
		if (min>it->second)
			min = it->second;
	return min;
}


ostream &operator <<(ostream &output, Gradebook& e)
{
	output << "====================================" << endl;
	output << "I�������i� ��� ���i���� �����" << endl;
	output << "�����: " << e.GetUDK() << endl;
	output << "����� �����: " << e.Gettitle() << endl;
	output << "�����: " << e.Getavtor() << endl;
	output << "����: " << e.getKurs() << endl;
	output << "��i���: " << endl;
	output << "�������: " << "��i���: " << endl;
	//map<string,int> RatingsOfSubjects;
	map<string, int>::iterator p;
	for (p = e.RatingsOfSubjects.begin(); p != e.RatingsOfSubjects.end(); p++)
	{
		cout << p->first << "\t" << p->second << "\n";
	}
	output << "�����������: " << e.Getedition() << endl;
	output << "�i� �������: " << e.Getyear() << endl;
	return output;
}

istream& operator>> (istream &input, Gradebook& e)
{
	SetConsoleOutputCP(1251);
	cout << endl;
	cout << "����-����� ����i�� i�������i� ��� ���i���� �����" << endl;
	char buffer[size1];
	string buffer1;
	try
	{
		cout << "�����: ";
		e.SetUDK(GetInt(input));
		cout << "�����: ";
		input.getline(buffer, size1, '\n');
		e.Setavtor(buffer);
		cout << "�����: ";
		input.getline(buffer, size1, '\n');
		e.Settitle(buffer);
		cout << "����: ";
		e.setKurs(GetInt(input));
		//map<char *,int> RatingsOfSubjects;
		//map<char*, int>::iterator p;
		for (int i = 0; i<5; i++)
		{
			cout << "�������: ";
			input.getline(buffer, size1, '\n');
			cout << "��i���: ";
			//input.getline(buffer1,size1,'\n');
			e.AddRatingsOfSubject(buffer, GetInt(input));
		}
		cout << "�����������: ";
		input.getline(buffer, size1, '\n');
		e.Setedition(buffer);
		cout << "�i�: ";
		e.Setyear(GetInt(input));
		input.clear();
	}
	catch (Error ex)
	{
		cout << ex.what() << endl;
	}
	return input;
}
