#ifndef TEXTURE_PACKER_MODEL_LOADING_HPP
#define TEXTURE_PACKER_MODEL_LOADING_HPP

#include "sbpt_generated_includes.hpp"

namespace texture_packer_model_loading {

std::vector<draw_info::IVPNTPRigged> convert_ivpntr_to_ivpntpr(std::vector<draw_info::IVPNTRigged> &ivptrs,
                                                               TexturePacker &texture_packer);
std::vector<draw_info::IVPTexturePacked> convert_ivpt_to_ivptp(std::vector<draw_info::IVPTextured> &ivptrs,
                                                               TexturePacker &texture_packer);
std::vector<draw_info::IVPNTexturePacked> convert_ivpnt_to_ivpntp(std::vector<draw_info::IVPNTextured> &ivptrs,
                                                                  TexturePacker &texture_packer);

draw_info::TransformedIVPTPGroup parse_model_into_tig(ResourcePath &rp, const std::string &model_path,
                                                      TexturePacker &texture_packer,
                                                      UniqueIDGenerator &object_id_generator,
                                                      BoundedUniqueIDGenerator &ltw_object_id_generator);

} // namespace texture_packer_model_loading

#endif // TEXTURE_PACKER_MODEL_LOADING_HPP
