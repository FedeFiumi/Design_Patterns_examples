#include <iostream>
#include <string>
#include <stdexcept>


// Target interface to adapt
class MediaPlayer {
public:
  virtual void play(std::string format, std::string name) = 0;
};

// Adaptee interface
class MediaPlayerAdvanced {
public:
  void playAudio(std::string name) {
    std::cout << "Playing audio: " << name << std::endl;
  }

  void playVideo(std::string name) {
    std::cout << "Playing video: " << name << std::endl;
  }
};

// Class Adapter
class MediaPlayerAdapter: public MediaPlayer, private MediaPlayerAdvanced {
public:
  void play(std::string format, std::string name) override {
    if (format == "audio") {
      playAudio(name);
    } else if (format == "video") {
      playVideo(name);
    } else {
      std::string expt_msg = "Invalid format: " + format;
      throw std::invalid_argument(expt_msg);
    }
  }
};

int main (int argc, char *argv[]) {
  MediaPlayerAdapter adapter;

  // Valid media formats
  adapter.play("audio", "song.mp3");
  adapter.play("video", "movie.mp4");

  // Invalid media formats
  adapter.play("image", "picture.png");

  std::cout << "PRESS ENTER:";
  std::cin.get();
  return 0;
}
