#include "libs/object_server/src/models/object_model/object_model.h"

ObjectModel::ObjectModel()
{
	if (mDatabase.get())
	{
		spdlog::info("DataBase wasn't set!");
	}
}

void ObjectModel::createTable()
{
	try
	{
		this->mDatabase->exec(
			"CREATE TABLE IF NOT EXISTS " + mTableName +
			" (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
			"file_name TEXT NOT NULL,"
			"file_content BLOB NOT NULL"
			"update_at TEXT NOT NULL);"
		);
	}
	catch (const std::exception e)
	{
		spdlog::info(e.what());
	}
}

void ObjectModel::setTableName(std::string& tableName)
{
	mTableName = tableName;
}

void ObjectModel::create(const FileObject& object)
{
	spdlog::info("[ObjectModel] create record of {}", object.fileName);
	try
	{
		// clang-format off
        SQLite::Statement query(*mDatabase.get(), " INSERT INTO " + mTableName + 
        " (file_name, " +
        " content, " +
		"update_at, "
        " VALUES (?,?,datetime('now','localtime'))");
		// clang-format on
		query.bind(1, object.fileName);
		query.bind(2, object.fileContent);
		query.exec();
	}
	catch (const std::exception& e)
	{
		spdlog::error(e.what());
	}
}
std::optional<FileObject> ObjectModel::read(const FileObject& object)
{
	spdlog::info("[ObjectModel] Read record of {}", object.fileName);
	try
	{
		std::optional<FileObject> result;
        SQLite::Statement query(*mDatabase.get(), " SELECT * FROM " + mTableName + "WHERE id = ?;" );
		if (query.executeStep())
		{
			query.bind(1,object.id);
			FileObject object;
			object.fileName = query.getColumn(2).getString();
			object.fileContent = query.getColumn(3).getString();
            result.emplace(object);
		}
		return result;
	}
	catch (const std::exception& e)
	{
		spdlog::error(e.what());
	}
}
void ObjectModel::remove(const FileObject& object)
{
	//may need it
	return;
}
void ObjectModel::update(const FileObject& object)
{
	return;
}
std::optional<std::vector<FileObject>> ObjectModel::readAll()
{
	std::optional<std::vector<FileObject>> placeHolder;
	return placeHolder;
}