

#pragma once
#include <memory>

#include "group_sig/devcore/CommonStruct.h"
#include "group_sig/devcore/easylog.h"

#include "bbs04/GroupSig_BBS.h"
#include "GroupSigInterface.h"

namespace dev
{
namespace eth
{
class GroupSigFactory
{
public:
    //static shared_ptr<GroupSigInterface> instance(GroupSigMethod& method)
    static shared_ptr<GroupSigInterface> instance(GroupSigMethod method)
    {
        switch (method)
        {
        case BBS04:
            LOG(DEBUG) << "BBS04 METHOD";
            return singleton<BBSGroupSig>::instance();
        case BS04_VLR:
            LOG(WARNING) << "BS04_VLR not implemented yet";
            break;
        case ACHM05:
            LOG(WARNING) << "ACHM05 not implemented yet";
            break;
        default:
            unkown_method(method);
            break;
        }
        LOG(INFO) << "UNKOWN GROUP SIG METHOD, USE BBS04 as default";
        return singleton<BBSGroupSig>::instance();
    }

    static void unkown_method(GroupSigMethod &group_method)
    {
        LOG(ERROR) << "GROUP_METHOD = " << group_method << " UNKOWN GROUP_METHOD";
    }
};
} // namespace eth
} // namespace dev
