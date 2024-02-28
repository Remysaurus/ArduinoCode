package frc.robot.subsystems;

import java.nio.Buffer;
import java.nio.ByteBuffer;

import edu.wpi.first.wpilibj.SPI;
import edu.wpi.first.wpilibj.SPI.Mode;
import edu.wpi.first.wpilibj.SPI.Port;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;
import edu.wpi.first.wpilibj2.command.SubsystemBase;

public class SPIport extends SubsystemBase {
  private ByteBuffer m_byteBuffer = ByteBuffer.allocate(4);
  private SPI m_port = new SPI(Port.kOnboardCS0);
  public SPIport() {
    m_port.setClockRate(100);
    
    m_port.setMode(Mode.kMode3); //data sampled on rising edge
  }

  public int read() {
    m_port.read(true, m_byteBuffer, 4);
    //SmartDashboard.putBoolean("has array", m_byteBuffer.hasArray());
    return m_byteBuffer.getInt(0);
    
  }

  @Override
  public void periodic() {
    
  }
}
