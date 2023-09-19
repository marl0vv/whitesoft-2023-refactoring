//Общий кусок кода, отвечающий за логику шифрования вынесен из функций, вызываемых по нажатию кнопок в отдельную функцию.  
//Общие строки, содержащие алфавиты, и значения размера алфавита были перенесы в члены класса (в этих кусках кода не присутствует).
 

//Функция определяет принадлежность каждого символа из строки inputString к алфавиту верхнего или нижнего регистра,
//после чего сдвигает его на offset символов вперёд. Берётся остаток от деления на размер алфавита, чтобы не выйти за пределы алфавита.
QString MainWindow::Caesar(QString const &inputString, int const offset)
{
    CaesarAlphabetChanged();
    QString outputString;
    for(int i = 0; i < inputString.size(); ++i)
    {
        if (m_upperAlphabet.contains(inputString[i]))
        {
            outputString.push_back(m_upperAlphabet.at(std::abs(m_upperAlphabet.indexOf(inputString[i]) + offset) % m_alphabetSize));
        }
        else if (m_lowerAlphabet.contains(inputString[i]))
        {
            outputString.push_back(m_lowerAlphabet.at(std::abs(m_lowerAlphabet.indexOf(inputString[i]) + offset) % m_alphabetSize));
        }
        else
        {
            outputString.push_back(inputString[i]);
        }
    }
    return outputString;
}

void MainWindow::on_pushButtonCaesarCypher_clicked()
{
    QString initialString = ui->lineEditCaesarInitial->text();
    int offset = ui->spinBoxCaesarOffset->value();
    QString outputString = Caesar(initialString, offset);

    ui->lineEditCaesarCrypted->setText(outputString);
}

void MainWindow::on_pushButtonCaesarDecypher_clicked()
{
    QString cryptedString = ui->lineEditCaesarCrypted->text();
    int offset =  m_alphabetSize - (ui->spinBoxCaesarOffset->value());
    QString outputString = Caesar(cryptedString, offset);

     ui->lineEditCaesarDecrypted->setText(outputString);
}