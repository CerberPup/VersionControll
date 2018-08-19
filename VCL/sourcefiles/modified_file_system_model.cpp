#include "headerfiles/modified_file_system_model.h"

#include "headerfiles/version_control_system.h"

#include <QBrush>

ModifiedFileSystemModel::ModifiedFileSystemModel(QObject *parent)
	: QFileSystemModel(parent)
{
}

ModifiedFileSystemModel::~ModifiedFileSystemModel()
{
}

QVariant ModifiedFileSystemModel::data(const QModelIndex& index, int role) const
{
	switch (role)
	{
	case Qt::ForegroundRole:
	{
		QString dir = filePath(index);
		if(VersionControllSystem::VersionControllManager::getInstance().findRoot(dir)!=nullptr)
		return QBrush(QColor(25, 150, 25));
		return QBrush(QColor(0,0,0));
	}
		break;
	case Qt::DisplayRole:
	{
		QVariant item = QFileSystemModel::data(index, role);
		std::string te = item.toString().toStdString();
		return item;
	}
		break;
	case Qt::UserRole:
	{
		return filePath(index);
	}
	default:
		return QFileSystemModel::data(index, role);
		break;
	}
}