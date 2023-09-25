#include <iostream>
#include <string>


// Target interface
class MediaPlayer {
public:
  virtual void play(std::string format, std::string name) = 0;
};

// Adaptee
class MediaPlayerAdvanced {
public:
  void playAudio(std::string name) {
    std::cout << "Playing audio: " << name << std::endl;
  }

  void playVideo(std::string name) {
    std::cout << "Playing video: " << name << std::endl;
  }
};

// Object Adapter
class MediaPlayerAdapter : public MediaPlayer {

public:
  MediaPlayerAdapter(MediaPlayerAdvanced* player) : advancedPlayer(player) {}

  void play(std::string format, std::string name) override {
    if (format == "audio") {
      advancedPlayer->playAudio(name);
    }
    else if (format == "video") {
      advancedPlayer->playVideo(name);
    } else {
      std::string expt_msg = "Invalid format: " + format;
      throw std::invalid_argument(expt_msg);
    }
  }

private:
  MediaPlayerAdvanced* advancedPlayer;

};

int main() {
  MediaPlayerAdvanced advancedPlayer;
  MediaPlayerAdapter adapter(&advancedPlayer);

  // Valid media formats
  adapter.play("audio", "song.mp3");
  adapter.play("video", "movie.mp4");

  // Unsupported format
  try{
    adapter.play("image", "picture.jpg");
  } catch (const std::invalid_argument& ex) {
    std::cout << ex.what() << std::endl;
  }

  return 0;
}
