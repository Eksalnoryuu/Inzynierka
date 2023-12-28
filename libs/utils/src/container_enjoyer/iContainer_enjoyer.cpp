#include "iContainer_enjoyer.h"

void IContainerEnjoyer::setFromContainerEnjoyer(IContainerEnjoyer* val)
{
    mDatabase = val->mDatabase;
}
void IContainerEnjoyer::createContainer(const std::string path)
{
    std::string copyPath = path;
    std::string folder = copyPath.erase( path.find_last_of("/"));
    if(!std::filesystem::exists(folder))
    {
        std::filesystem::create_directory(folder);
    }
    mDatabase = std::make_shared<SQLite::Database>(std::filesystem::path(path), SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
}