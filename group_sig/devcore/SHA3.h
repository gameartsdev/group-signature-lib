
/** @file SHA3.h
 * @author Gav Wood <i@gavwood.com>
 * @date 2014
 *
 * The FixedHash fixed-size "hash" container type.
 */

#pragma once

#include <string>

namespace GroupSig
{
void sha3(unsigned char* digest, unsigned char* input,
        unsigned int len);

}
