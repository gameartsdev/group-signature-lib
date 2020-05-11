
#pragma once
#include "group_sig/devcore/CommonStruct.h"
#include "group_sig/devcore/ConfigParser.h"
#include "group_sig/devcore/CommonFunc.h"
#include "group_sig/devcore/easylog.h"

#include "LinearPair.h"

namespace dev
{
namespace eth
{
//签名算法枚举
/*enum GroupSigMethod
{
    BBS04=0x00,
    BS04_VLR=0x01,
    ACHM05=0x02
};*/

class GroupSigInterface
{
public:
    string gpk_info_dir;
    std::string linear_config_path; //线性对配置文件路径
    shared_ptr<LinearPair> p_linear;
    Locker m_lock; //lock p_linear access
    shared_ptr<ConfigParserInterface<JsonConfigParser>> pconfig_interface;

public:
    GroupSigInterface(const std::string &config_path,
                      std::string dir = "data") : gpk_info_dir(dir),
                                                  linear_config_path(config_path), m_lock(Locker())
    {
        if ("" == dir)
            gpk_info_dir = "data";

        if (!create_directory(gpk_info_dir))
            LOG(ERROR) << "CREATE DIRECTORY " << gpk_info_dir << " FAILED";

        //创建线性表配置对象
        if (linear_config_path != "")
        {
            pconfig_interface = make_shared<ConfigParserInterface<JsonConfigParser>>();
            //加载json类型配置对象
            pconfig_interface->create(linear_config_path);
        }
        //创建线性对接口
        p_linear = LinearPairFactory::create(pconfig_interface);
    }

    virtual ~GroupSigInterface() {}

    std::string get_gpk_dir()
    {
        return gpk_info_dir;
    }

    //生成群: (群公钥，群主私钥)
    virtual int create_group(string &result, const std::string &param) = 0;

    //使用群签名算法签名消息
    virtual int group_sig(string &result, const std::string &param) = 0;

    //群签名验证
    virtual int group_verify(int &valid, const std::string &param) = 0;

    //打开群签名
    virtual int group_open(string &result, const std::string &param) = 0;

    //为成员颁发私钥
    virtual int gen_gsk(string &result, const std::string &param) = 0;

    //撤销群成员
    virtual int gm_revoke(string &result, const std::string &param) = 0;

    //群成员撤销后，更新私钥
    virtual int update_gsk(string &result, const std::string &param) = 0;

    void unkown_method(GroupSigMethod group_method)
    {
        LOG(ERROR) << "GROUP_METHOD = " << group_method << " UNKOWN GROUP_METHOD";
    }
};
} // namespace eth
} // namespace dev
