#include "SetMotion.h"

SetMotion::SetMotion(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	intial();
}

SetMotion::~SetMotion()
{

}

void SetMotion::intial()
{
	setWhatsThis(u8"红色为高电平，绿色为低电平");
	
	setmachinery(1);

	ui.dial->setMinimum(0);
	ui.dial->setMaximum(20000);
	ui.dial->setNotchesVisible(true);

	machinerylist = *(new map<int, int>());

	DateHelper::readSpeed();
	machinerylist[1] = DateHelper::speed_1;
	ui.lineEdit->setText(QString::number(machinerylist[1]));

	distance = 1000;
	ui.lineEdit_3->setText(QString::number(distance));

	ui.radioButtonplus->setChecked(true);
	
	icongreen.addFile(QStringLiteral(":/CameraDtecte1/Resources/green.jpg"), QSize(), QIcon::Normal, QIcon::Off);
	iconred.addFile(QStringLiteral(":/CameraDtecte1/Resources/red.png"), QSize(), QIcon::Normal, QIcon::Off);


//	ui.toolButton_4->setIcon(icongreen);

	//read_inbitatate();
}

void SetMotion::setmachinery(int num)
{
	QString name = "radioButton_" +QString::number( num);
	qDebug() << name;
	QRadioButton *tempButton = this->findChild< QRadioButton*>(name);
	currentEM = num;
	tempButton->setChecked(true);
}

void SetMotion::read_inbitatate()
{
	
	QString buttonname = "toolButton_in";
	for (size_t i = 0; i < Card::inbitnum; i++)
	{
		QString Sname = buttonname + QString::number(i);
		int state = d2210_read_inbit(Card::Axis0, i);
		set_icon(Sname,state);
	}
}

void SetMotion::read_inoutbitstate()
{
	QString buttonname = "toolButton_out";
	for (size_t i = 0; i < Card::outbitnum; i++)
	{
		QString Sname = buttonname + QString::number(i);
		int state = d2210_read_outbit(Card::Axis0, i);
		set_icon(Sname, state);
	}
}



void SetMotion::set_icon(QString name, int state)
{
	QToolButton *tempButton = this->findChild<QToolButton *>(name);

	if (state ==Card::ON )
	{
		tempButton->setIcon(icongreen);
	}
	else
	{
		tempButton->setIcon(iconred);
	}
}
void SetMotion::run()
{
	onrun = true;
	int currentPos = (int)d2210_get_encoder(Card::Axis0);
	int p0 = currentPos;
	d2210_t_vmove(Card::Axis0, ui.radioButtonplus->isChecked());
	while (currentPos < p0 + distance || currentPos > p0 - distance || onrun ==false )
	{
		currentPos = (int)d2210_get_encoder(Card::Axis0);
	}
	d2210_imd_stop(Card::Axis0);
	onrun = false;
}
void SetMotion::getmachinery(bool ok)
{
	if (ok)
	{
		currentEM = sender()->objectName().remove("radioButton_").trimmed().toInt();
		qDebug() << currentEM;
	}
}
void SetMotion::getspeed()
{
	machinerylist[currentEM] = ui.dial->value();
	ui.lineEdit->setText(QString::number(ui.dial->value()));
}
void SetMotion::startmotion()
{
	machinerylist[currentEM] = ui.lineEdit->text().trimmed().toInt();
	d2210_write_SEVON_PIN(Card::Axis0, Card::ON);
	d2210_set_profile(Card::Axis0, Card::minspeed, machinerylist[currentEM], Card::acc, Card::acc);
	d2210_set_position(Card::Axis0, 200000);
	d2210_set_encoder(Card::Axis0, 200000);
	distance = ui.lineEdit_3->text().trimmed().toInt();
	std::thread t(&SetMotion::run, this);
	t.detach();
	
	qDebug() << d2210_get_encoder(Card::Axis0);
}
void SetMotion::savequit()
{
	onrun = false;
	DateHelper::saveSpeed( machinerylist[1]);
	this->accept();
}
void SetMotion::changestate() {

	QToolButton *tempButton = (QToolButton *)sender();
	int  name = tempButton->text().trimmed().toInt();
	qDebug() << name;
	int state = d2210_read_outbit(Card::Axis0, name);

	int newstate = (state != 0) ? 0 : 1;

	d2210_write_outbit(Card::Axis0, name, newstate);

	if (state == Card::ON)
	{
		tempButton->setIcon(icongreen);
	}
	else
	{
		tempButton->setIcon(iconred);
	}

}