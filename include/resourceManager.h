#pragma once

#include <map>
#include <string>
#include <SDL2/SDL.h>

class ResourceManager
{
public:
    ResourceManager() = default;
    ResourceManager(ResourceManager const&) = delete;

    ResourceManager operator=(ResourceManager const&) = delete;

    void changePath(std::string const& path);
    void changeRenderer(SDL_Renderer *renderer);

    SDL_Texture* getTexture(std::string const& name) const;
    void addTexture(std::string const& name);
    bool textureExists(std::string name) const; // Temporary
    std::string const& path() const;
private:
    std::string _path{};
    SDL_Renderer *_renderer{};

    std::map<std::string, SDL_Texture*> _textures{};
};