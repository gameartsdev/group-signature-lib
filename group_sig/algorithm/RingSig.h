
#pragma once
#include <utility>

#if !defined(__cplusplus)
extern "C"
{
#endif

#if defined(__cplusplus)
  namespace RingSigApi
  {
  namespace LinkableRingSig
  {
#endif

  /******************* notification *********************
   *                                                    *
   *  All interfaces would throw string type exception  *
   *                                                    *
   ******************** notification ********************/

  /* @function: generate params for specified ring
     * @params: 1. bit_len: length of ring param element
     *          default is 1024(1024-security)
     * @ret: param_info
     */
  std::string setup_ring(const int &bit_len = 1024);

  // c language style interface with same funtion, please ignore
  int setup_ring(std::string &param_info,
                 const int &bit_len = 1024);

  /* @function: generate private key for member of 
     *            specified ring
     * @params: 1. param_info: param info of specified ring
     *          2. pos: position of this ring member
     *
     * @ret: key pairs: the first is private key, and the second is public key
     */
  std::pair<std::string, std::string> join_ring(const std::string &param_info,
                                                const std::string &pos);

  // c language style interface with same funtion, please ignore
  int join_ring(std::string &private_key_info,
                std::string &public_key_info,
                const std::string &param_info,
                const std::string &pos);

  /* @function: generate signature with linkable ring sig
     *      algorithm for specified ring member
     * @param: 1. message: plain text
     *         2. public_key_list: public key list used to
     *            generate linkable signature
     *         3. private_key_info:private key of ring member 
     *            to generate signature
     *         4. param_info: param info of ring the member 
     *         belongs to
     * @ret: signature
     */
  std::string ring_sig(const std::string &message,
                       const std::vector<std::string> &public_key_list,
                       const std::string &private_key_info,
                       const std::string &param_info);

  // c language style interface with same funtion, please ignore
  int ring_sig(std::string &sig,
               const std::string &message,
               const std::vector<std::string> &public_key_list,
               const std::string &private_key_info,
               const std::string &param_info);

  /* @function: verify given signature is valid or not
     * @params: 1. sig: signature to be verified
     *          2. message: plain text 
     *          3. param_info: param inforamtion of ring this signature 
     *             belongs to 
     * @ret: true: signature is valid; false: signature is invalid;
     */
  bool ring_verify(const std::string &sig,
                   const std::string &message,
                   const std::string &param_info);

  // c language style interface with same funtion, please ignore
  int ring_verify(bool &valid,
                  const std::string &sig,
                  const std::string &message,
                  const std::string &param_info);

#if defined(__cplusplus)
  }
  }
#endif
#if !defined(__cplusplus)
}
#endif
