#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	EvenOdd::MyForm form;
	Application::Run(% form);
}

int fieldSize;
int** gameField;
int x; 
int y;
int emptyCells;


void EvenOdd::MyForm::calculationFunc(int** gameField, int fieldSize)
{
    int even = 0;
    int odd = 0;

    int sumCols;
    int sumRows;
    int sumDiagonal;

    if (emptyCells == 0) {

        ///////////////////////////////// Rows
        for (int i = 0; i < fieldSize; i++) {

            sumRows = 0;

            for (int j = 0; j < fieldSize; j++) {
                sumRows += gameField[i][j];
            }
            if (sumRows % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }

        ///////////////////////////////// Columns
        for (int i = 0; i < fieldSize; i++) {

            sumCols = 0;

            for (int j = 0; j < fieldSize; j++) {
                sumCols += gameField[j][i];
            }
            if (sumCols % 2 == 0) {
                even++;
            }
            else {
                odd++;
            }
        }

        ///////////////////////////////// Diagonal
        sumDiagonal = 0;

        for (int i = 0; i < fieldSize; i++) {
            sumDiagonal += gameField[i][i];
        }
        if (sumDiagonal % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }

        sumDiagonal = 0;

        int j = fieldSize - 1;

        for (int i = 0; i < fieldSize; i++) {
            sumDiagonal += gameField[i][j];
            j = j - 1;
        }

        if (sumDiagonal % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }

        if (even > odd) {
            MessageBox::Show("Четный выиграл!", "Игра окончена!");
        }
        else if (even < odd) {
            MessageBox::Show("Нечетный выиграл!", "Игра окончена!");
        }
        else {
            MessageBox::Show("Ничья!", "Игра окончена!");
        }
    }
}

System::Void EvenOdd::MyForm::ExitMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}


System::Void EvenOdd::MyForm::RulesMenu_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Добро пожаловать в игру \"Четный-Нечетный\"!\n\nПравила игры очень просты:\nСначала 2 игрока договариваются, кто из них четный, а кто нечетный." + 
        "Игроки по очереди ставят 0 и 1 в любые свободные клетки поля. Цель четного игрока - ставить цифры так, чтобы суммы столбцов, строк и диагоналей получались четными" + 
        "Цель нечетного игрока - наоборот. Все поля будут заполнены, программа назовет победителя. Выиграл тот, чьих сумм показалось больше. \n\nУдачи!", "Правила");
}


System::Void EvenOdd::MyForm::numericFieldSize_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	fieldSize = Convert::ToInt32(numericFieldSize->Value);
    emptyCells = fieldSize * fieldSize;
}


System::Void EvenOdd::MyForm::fieldGenerateButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	gameField = new int* [fieldSize];

	for (int i = 0; i < fieldSize; i++) {
		gameField[i] = new int[fieldSize];
	}

	////////////////////////////////// Filling

	for (int i = 0; i < fieldSize; i++) {
		for (int j = 0; j < fieldSize; j++) {
			gameField[i][j] = 4;
		}
	}

	dataGridView->RowCount = fieldSize;
	dataGridView->ColumnCount = fieldSize;

	ShowField();

	dataGridView->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dataGridView->AutoResizeColumns();
}


System::Void EvenOdd::MyForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    x = Convert::ToInt32(dataGridView->CurrentCell->RowIndex);
    y = Convert::ToInt32(dataGridView->CurrentCell->ColumnIndex);

    textBox1->Text = Convert::ToString(x+1);
    textBox2->Text = Convert::ToString(y+1);
}


System::Void EvenOdd::MyForm::set1_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (emptyCells > 0) {
        if (gameField[x][y] == 4) {
            gameField[x][y] = 1;
            ShowField();
            emptyCells--;
        }
        else {
            MessageBox::Show("Старина, это поле занято! Выбери другое.", "Ошибка!");
        }
    }
    calculationFunc(gameField, fieldSize);
}


System::Void EvenOdd::MyForm::set0_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (emptyCells > 0) {
        if (gameField[x][y] == 4) {
            gameField[x][y] = 0;
            ShowField();
            emptyCells--;
        }
        else {
            MessageBox::Show("Старина, это поле занято! Выбери другое.", "Хер там!");
        }
    }
    calculationFunc(gameField, fieldSize);
}


void EvenOdd::MyForm::ShowField()
{	
	for (int i = 0; i < fieldSize; i++) {
		for (int j = 0; j < fieldSize; j++) {
			if (gameField[i][j] == 4) {
				dataGridView->Rows[i]->Cells[j]->Value = "-";
			}
			else {
				dataGridView->Rows[i]->Cells[j]->Value = gameField[i][j];
			}
		}
	}
}
