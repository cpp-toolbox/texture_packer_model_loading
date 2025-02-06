#include "texture_packer_model_loading.hpp"

namespace texture_packer_model_loading {

std::vector<IVPNTPRigged> convert_ivpnt_to_ivpntpr(std::vector<IVPNTRigged> &ivptrs, TexturePacker &texture_packer) {
    std::vector<IVPNTPRigged> ivpntprs = {};
    for (auto &ivpntr : ivptrs) {
        std::vector<glm::vec2> packed_texture_coordinates;
        for (auto &tc : ivpntr.texture_coordinates) {
            auto ptc = texture_packer.get_packed_texture_coordinate(ivpntr.texture_path, tc);
            packed_texture_coordinates.push_back(ptc);
        }
        int packed_texture_index = texture_packer.get_packed_texture_index_of_texture(ivpntr.texture_path);
        IVPNTPRigged ivpntpr(ivpntr.indices, ivpntr.xyz_positions, ivpntr.normals, packed_texture_coordinates,
                             packed_texture_index, ivpntr.texture_path, ivpntr.bone_data);
        ivpntprs.push_back(ivpntpr);
    }
    return ivpntprs;
}

std::vector<IVPTexturePacked> convert_ivpt_to_ivptp(std::vector<IVPTextured> &ivpts, TexturePacker &texture_packer) {
    std::vector<IVPTexturePacked> ivptps = {};
    for (auto &ivpt : ivpts) {
        std::vector<glm::vec2> packed_texture_coordinates;
        for (auto &tc : ivpt.texture_coordinates) {
            auto ptc = texture_packer.get_packed_texture_coordinate(ivpt.texture_path, tc);
            packed_texture_coordinates.push_back(ptc);
        }
        int packed_texture_index = texture_packer.get_packed_texture_index_of_texture(ivpt.texture_path);
        int texture_bounding_box_index =
            texture_packer.get_packed_texture_bounding_box_index_of_texture(ivpt.texture_path);
        IVPTexturePacked ivptp(ivpt.indices, ivpt.xyz_positions, ivpt.texture_coordinates, packed_texture_coordinates,
                               packed_texture_index, texture_bounding_box_index, ivpt.texture_path);
        ivptps.push_back(ivptp);
    }
    return ivptps;
}

std::vector<IVPNTexturePacked> convert_ivpnt_to_ivpntp(std::vector<IVPNTextured> &ivpnts,
                                                       TexturePacker &texture_packer) {
    std::vector<IVPNTexturePacked> ivpntps = {};
    for (auto &ivpnt : ivpnts) {
        std::vector<glm::vec2> packed_texture_coordinates =
            texture_packer.get_packed_texture_coordinates(ivpnt.texture_path, ivpnt.texture_coordinates);
        int packed_texture_index = texture_packer.get_packed_texture_index_of_texture(ivpnt.texture_path);
        int texture_bounding_box_index =
            texture_packer.get_packed_texture_bounding_box_index_of_texture(ivpnt.texture_path);
        IVPNTexturePacked ivpntp(ivpnt.indices, ivpnt.xyz_positions, ivpnt.normals, ivpnt.texture_coordinates,
                                 packed_texture_coordinates, packed_texture_index, texture_bounding_box_index,
                                 ivpnt.texture_path);
        ivpntps.push_back(ivpntp);
    }
    return ivpntps;
}
} // namespace texture_packer_model_loading
