class Advcalclib < Formula
  desc "Advanced Calculator Library for C++"
  homepage "https://github.com/Bkiser2000/advcalclib"
  url "https://github.com/Bkiser2000/advcalclib/archive/refs/tags/v1.0.1.tar.gz"
  sha256 "0a60ff7bf554ce2c67d19f436643242e6bfcf5529fe3e9d61cad37f0335610c4"
  license "MIT"
  
  depends_on "cmake" => :build
  
  def install
    system "cmake", "-B", "build", "-S", ".",
           "-DCMAKE_INSTALL_PREFIX=#{prefix}",
           "-DCMAKE_BUILD_TYPE=Release"
    system "cmake", "--build", "build"
    lib.install Dir["build/libadvcalclib.so*"]
    include.install Dir["include/*.hpp"]
  end
end
