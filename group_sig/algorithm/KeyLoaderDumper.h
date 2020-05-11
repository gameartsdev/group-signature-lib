
#pragma once

#include <string>
#include <pbc/pbc.h>

#include "group_sig/devcore/ConfigParser.h"
#include "group_sig/devcore/CommonFunc.h"
#include "group_sig/devcore/easylog.h"
#include "group_sig/devcore/StatusCode.h"

#include "bbs04/GroupSig_BBS.h"
#include "bbs04/GroupSig_BBS_Impl.h"
#include "GroupSigInterface.h"

using namespace RetCode::GroupSigStatusCode;
using namespace RetCode::CommonStatusCode;

namespace dev
{
namespace eth
{

//公私钥 load/store proxy类
template <typename T>
class KeyManager
{
public:
    //加载公钥信息
    template <typename... Args>
    static int load_gpk(Args &&... args)
    {
        return T::load_gpk(std::forward<Args>(args)...);
    }

    //保存公钥信息
    template <typename... Args>
    static int store_gpk(Args &&... args)
    {
        return T::store_gpk(std::forward<Args>(args)...);
    }

    //###群主私钥信息管理
    template <typename... Args>
    static int store_gmsk(Args &&... args)
    {
        return T::store_gmsk(std::forward<Args>(args)...);
    }

    template <typename... Args>
    static int load_gmsk(Args &&... args)
    {
        return T::load_gmsk(std::forward<Args>(args)...);
    }

    //###群成员私钥信息管理
    template <typename... Args>
    static int store_gsk(Args &&... args)
    {
        return T::store_gsk(std::forward<Args>(args)...);
    }

    template <typename... Args>
    static int load_gsk(Args &&... args)
    {
        return T::load_gsk(std::forward<Args>(args)...);
    }

    //签名信息
    template <typename... Args>
    static int load_sig(Args &&... args)
    {
        return T::load_sig(std::forward<Args>(args)...);
    }

    template <typename... Args>
    static int store_sig(Args &&... args)
    {
        return T::store_sig(std::forward<Args>(args)...);
    }
};

class BBSKey
{
public:
    //根据gpk_str 恢复gpk系统参数
    static int load_gpk(bbs_group_public_key_ptr p_gpk,
                        const string &gpk_str,
                        bbs_sys_param_ptr p_sys_param);

    //将gpk信息存储到gpk_info(json格式)
    static int store_gpk(std::string &gpk_info,
                         bbs_group_public_key_ptr p_gpk);

    //保存私钥信息: v1:私钥不加密
    //TODO: 私钥加密存储
    static int store_gmsk(std::string &gmsk_info,
                          bbs_manager_private_key_ptr p_gmsk);

    //加载私钥信息
    //TODO: 私钥加密存储 && 解密load
    static int load_gmsk(bbs_manager_private_key_ptr p_gmsk,
                         const std::string &gmsk_info, bbs_sys_param_ptr p_sys_param);

    //###群成员私钥信息管理
    //TODO: 私钥加密管理
    static int store_gsk(std::string &gsk_info,
                         bbs_group_private_key_ptr gsk);

    //加载群成员私钥
    //TODO: 加密后私钥解密
    static int load_gsk(bbs_group_private_key_ptr gsk,
                        const std::string &gsk_info, bbs_sys_param_ptr p_sys_param);
    static int store_sig(string &sig, BBS04Signature &sig_struct);
    static int load_sig(BBS04Signature &sig_struct, const string &sig);
};
} // namespace eth
} // namespace dev
