#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace VerityAssets {

    struct Texture {
        unsigned int id;
        int width;
        int height;
    };

    struct Model {
        std::vector<float> vertices;
        std::vector<unsigned int> indices;
        Texture diffuseMap;
    };

    class AssetLoader {
    public:
        static AssetLoader& getInstance() {
            static AssetLoader instance;
            return instance;
        }

        Model loadEntityModel(const std::string& modelName);
        Texture loadTexture(const std::string& texturePath);
        void unloadAll();

    private:
        AssetLoader() {}
        std::unordered_map<std::string, Model> modelCache;
        std::unordered_map<std::string, Texture> textureCache;
    };
}
