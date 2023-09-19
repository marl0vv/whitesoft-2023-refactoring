//Реализация шифрования методом Цезаря.
//Писалось на Qt, исходная строка получалась из поля окна для взаимодействия с пользователем.
//Так как вырвал функции из цельного Qt-проекта, то отдельно они не скомпилируются и не запустятся,
//если нужно, то перепишу, чтобы работало с консолью.

//Проблему вижу в том, что алгоритм дешифрования практически полностью аналогичен алгоритму дешифрования.
//Также дублируются исходные алфавиты, которые нужны, чтобы менять позиции букв, размер алфавита и шаг, на который будет сдвигаться зашифрованное сообщение.
//Перепишем согласно принципу DRY, чтобы не дублировать код.
//Отрефакторенный код будет в отдельной ветке в репозитории.
void MainWindow::on_pushButtonCaesarCypher_clicked()
{
    QString initialString = ui->lineEditCaesarInitial->text();
    QString upperAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    QString lowerAlphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    QString outputString;
    const int alphabetSize = 33;
    const int offset = 16;
    for(int i = 0; i < initialString.size(); ++i)
    {
        if (upperAlphabet.contains(initialString[i]))
        {
            outputString.push_back(upperAlphabet[(upperAlphabet.indexOf(initialString[i]) + offset) % alphabetSize]);
        }
        else if (lowerAlphabet.contains(initialString[i]))
        {
            outputString.push_back(lowerAlphabet[(lowerAlphabet.indexOf(initialString[i]) + offset) % alphabetSize]);
        }
        else
        {
            outputString.push_back(initialString[i]);
        }
    }
    ui->lineEditCaesarCrypted->setText(outputString);
}


void MainWindow::on_pushButtonCaesarDecypher_clicked()
{
    QString cryptedString = ui->lineEditCaesarCrypted->text();
    QString upperAlphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    QString lowerAlphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    QString outputString;
    const int alphabetSize = 33;
    const int offset = 17;

    for(int i = 0; i < cryptedString.size(); ++i)
    {
        if (upperAlphabet.contains(cryptedString[i]))
        {
            outputString.push_back(upperAlphabet[(upperAlphabet.indexOf(cryptedString[i]) + offset) % alphabetSize]);
        }
        else if (lowerAlphabet.contains(cryptedString[i]))
        {
            outputString.push_back(lowerAlphabet[(lowerAlphabet.indexOf(cryptedString[i]) + offset) % alphabetSize]);
        }
        else
        {
            outputString.push_back(cryptedString[i]);
        }
    }
    ui->lineEditCaesarDecrypted->setText(outputString);
}