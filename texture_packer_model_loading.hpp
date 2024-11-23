#ifndef TEXTURE_PACKER_MODEL_LOADING_HPP
#define TEXTURE_PACKER_MODEL_LOADING_HPP

#include "sbpt_generated_includes.hpp"

class IVPTexturePacked {
  public:
    IVPTexturePacked(std::vector<unsigned int> indices, std::vector<glm::vec3> xyz_positions,
                     std::vector<glm::vec2> packed_texture_coordinates, int packed_texture_index,
                     const std::string &texture)
        : indices(indices), xyz_positions(xyz_positions), packed_texture_coordinates(packed_texture_coordinates),
          packed_texture_index(packed_texture_index), texture(texture) {};
    Transform transform;
    std::vector<unsigned int> indices;
    std::vector<glm::vec3> xyz_positions;
    std::vector<glm::vec2> packed_texture_coordinates;
    int packed_texture_index;
    std::string texture;
};

class IVPNTexturePacked {
  public:
    IVPNTexturePacked(std::vector<unsigned int> indices, std::vector<glm::vec3> xyz_positions,
                      std::vector<glm::vec3> normals, std::vector<glm::vec2> packed_texture_coordinates,
                      int packed_texture_index, const std::string &texture)
        : indices(indices), xyz_positions(xyz_positions), normals(normals),
          packed_texture_coordinates(packed_texture_coordinates), packed_texture_index(packed_texture_index),
          texture(texture) {};
    Transform transform;
    std::vector<unsigned int> indices;
    std::vector<glm::vec3> xyz_positions;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> packed_texture_coordinates;
    int packed_texture_index;
    std::string texture;
};

std::vector<IVPTPRigged> convert_ivpt_to_ivptpr(std::vector<IVPTRigged> &ivptrs, TexturePacker &texture_packer);
std::vector<IVPTexturePacked> convert_ivpt_to_ivptp(std::vector<IVPTextured> &ivptrs, TexturePacker &texture_packer);
std::vector<IVPNTexturePacked> convert_ivpnt_to_ivpntp(std::vector<IVPNTextured> &ivptrs,
                                                       TexturePacker &texture_packer);

#endif // TEXTURE_PACKER_MODEL_LOADING_HPP
