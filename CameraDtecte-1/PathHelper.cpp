#include"PathHelper.h"
QString PathHelper::pastproductname = "";
QString PathHelper::pastproductpath = "";
QString PathHelper::currentproductname = "";
QString PathHelper::currentproductpath = "";
QString PathHelper::datapath = "";
QString PathHelper::productPath = "";


PathHelper::PathHelper()
{
}

PathHelper::~PathHelper()
{
}


void PathHelper::setproduct()
{
}




bool PathHelper::newproduct(QString ProductName)
{

	PathHelper::intial();
	currentproductpath = productPath + "/" + ProductName;

	if (!createDirectory(currentproductpath))
	{
		currentproductpath = pastproductpath;
		currentproductname = pastproductname;
		return false;
	}
	currentproductname = ProductName;
	//qDebug() <<currentproductname;
	return true;

}

bool PathHelper::selectproduct(QString ProductName)
{
	PathHelper::intial();
	currentproductpath = productPath + "/" + ProductName;
	currentproductname = ProductName;
	return false;
}

bool PathHelper::createDirectory(QString folder)
{

	// ���Ŀ¼�Ƿ���ڣ������������½�
	QDir dir;
	if (!dir.exists(folder))
	{
		bool res = dir.mkpath(folder);
		return true;
	}
	else 
	{
		return false;
	}
}

bool PathHelper::DelDir(const QString  name)
{
	PathHelper::intial();
	QString path = productPath + "/" + name;
	if (path.isEmpty()) {
		return false;
	}
	QDir dir(path);
	if (!dir.exists()) {
		return true;
	}
	bool flag =RemoveDirectory(path.toStdWString().c_str());
	//dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //���ù���
	//QFileInfoList fileList = dir.entryInfoList(); // ��ȡ���е��ļ���Ϣ
	//foreach(QFileInfo file, fileList) { //�����ļ���Ϣ
	//	if (file.isFile()) { // ���ļ���ɾ��
	//		file.dir().remove(file.fileName());
	//	}
	//	else { // �ݹ�ɾ��
	//		DelDir(file.absoluteFilePath());
	//	}
	//}
	return flag; // ɾ���ļ���
}

void PathHelper::GetAllFileFolder(std::vector<QString>& folder)
{
	PathHelper::intial();

	QDir dir(productPath);
	dir.setFilter(QDir::Dirs);

	foreach(QFileInfo fullDir, dir.entryInfoList())
	{
		if (fullDir.fileName() == "." || fullDir.fileName() == "..") continue;
		folder.push_back(fullDir.baseName());

		// this->GetAllFileFolder(fullDir.absoluteFilePath(), folder);
	}


}

void PathHelper::intial()
{
	datapath = QDir::currentPath()+"/Data";
	productPath = datapath + "/Product";
	pastproductname = currentproductname;
	pastproductpath = currentproductpath;
}
