#include "zmq.h"
#include "zmq.hpp"
#include "zmq_addon.hpp"
#include "spdlog/spdlog.h"
class ObjectServer
{
public:
	ObjectServer(){};
	~ObjectServer(){};
    void Init(const std::string address);
    void Connect();
    void Start();
private:
	std::unique_ptr<zmq::context_t> mContext;
    std::shared_ptr<zmq::socket_t> mPubSocket;
    std::shared_ptr<zmq::socket_t> mSubSocket;
    std::string mAddress;
};