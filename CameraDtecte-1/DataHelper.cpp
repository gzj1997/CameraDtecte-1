#include"DataHelper.h"

int DateHelper::speed_1 = 0;
QString DateHelper::CCD = "";
int DateHelper::gain = -1;
int DateHelper::pixel = -1;
double DateHelper::expose = -1;

DateHelper::DateHelper()
{
}

DateHelper::~DateHelper()
{
}

void DateHelper::setconsole()
{

}

void DateHelper::readSpeed()
{
	QString dpath = QDir::currentPath() + "/Data/Position.xml";
	QFile file(dpath);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		std::cerr << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString())
			<< std::endl;
	}
	QXmlStreamReader reader(&file);
	while (!reader.atEnd()) {
		reader.readNext();
		if (reader.isStartElement()) {
			if (reader.name() == "Speed")
			{
				speed_1 = reader.attributes().value("speed_1").toInt();
				// qDebug() << reader.readElementText();
			}

			// qDebug() << reader.name() << reader.attributes().value("speed_zong").toInt();
		}
	}
	file.close();
	if (reader.hasError()) {
		std::cerr << "Error: Failed to parse file "
			<< qPrintable(dpath) << ": "
			<< qPrintable(reader.errorString()) << std::endl;
	}
	else if (file.error() != QFile::NoError) {
		std::cerr << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString())
			<< std::endl;
	}
}

void DateHelper::saveSpeed(int k)
{
	QString dpath = QDir::currentPath() + "/Data/Position.xml";
	QFile file(dpath); //���·��������·������Դ·��������
	if (!file.open(QFile::ReadOnly))
		return;
	//����һ����ǩ��,���֪��xml�Ľṹ��ֱ�Ӷ�λ���Ǹ���ǩ�϶������
	//�����ñ����ķ���ȥƥ��tagname����attribut��value������
	QDomDocument doc;
	if (!doc.setContent(&file))
	{
		file.close();
		return;
	}
	file.close();

	QDomElement root = doc.documentElement();
	QDomNodeList list = root.elementsByTagName("Speed");
	QDomNode node = list.at(0);
	node.toElement().setAttribute("speed_1", k);
	speed_1 = k;
	if (!file.open(QFile::WriteOnly | QFile::Truncate))
		return;
	//������ļ�
	QTextStream out_stream(&file);
	doc.save(out_stream, 4); //����4��
	file.close();
}

void DateHelper::savecamera()
{
	QString dpath = QDir::currentPath() + "/Data/CameraSettings.xml";
	QFile file(dpath); //���·��������·������Դ·��������
	if (!file.open(QFile::ReadOnly))
		return;
	//����һ����ǩ��,���֪��xml�Ľṹ��ֱ�Ӷ�λ���Ǹ���ǩ�϶������
	//�����ñ����ķ���ȥƥ��tagname����attribut��value������
	QDomDocument doc;
	if (!doc.setContent(&file))
	{
		file.close();
		return;
	}
	file.close();

	QDomElement root = doc.documentElement();
	QDomNodeList list = root.elementsByTagName(CCD);
	QDomNode node = list.at(0);
	node.toElement().setAttribute("pixel", pixel);
	node.toElement().setAttribute("ExposureTime", expose);
	node.toElement().setAttribute("Gain", gain);
	if (!file.open(QFile::WriteOnly | QFile::Truncate))
		return;
	//������ļ�
	QTextStream out_stream(&file);
	doc.save(out_stream, 4); //����4��
	file.close();
}

void DateHelper::setcamera(QString name, int g, int p, double e)
{
	CCD = name;
	gain = g;
	pixel = p;
	expose = e;

	savecamera();

	CCD = "";
	gain = -1;
	pixel = -1;
	expose = -1;
}
