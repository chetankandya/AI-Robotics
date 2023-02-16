// Auto-generated. Do not edit!

// (in-package air_lab3.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class ExecuteTstRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.tst_file = null;
    }
    else {
      if (initObj.hasOwnProperty('tst_file')) {
        this.tst_file = initObj.tst_file
      }
      else {
        this.tst_file = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ExecuteTstRequest
    // Serialize message field [tst_file]
    bufferOffset = _serializer.string(obj.tst_file, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ExecuteTstRequest
    let len;
    let data = new ExecuteTstRequest(null);
    // Deserialize message field [tst_file]
    data.tst_file = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.tst_file);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'air_lab3/ExecuteTstRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '22e6d4affee3f17832329ed194a5ee94';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string tst_file         # Name of the TST file to execute
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ExecuteTstRequest(null);
    if (msg.tst_file !== undefined) {
      resolved.tst_file = msg.tst_file;
    }
    else {
      resolved.tst_file = ''
    }

    return resolved;
    }
};

class ExecuteTstResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
      this.error_message = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
      if (initObj.hasOwnProperty('error_message')) {
        this.error_message = initObj.error_message
      }
      else {
        this.error_message = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ExecuteTstResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    // Serialize message field [error_message]
    bufferOffset = _serializer.string(obj.error_message, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ExecuteTstResponse
    let len;
    let data = new ExecuteTstResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [error_message]
    data.error_message = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.error_message);
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'air_lab3/ExecuteTstResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6fe914479ce03184a758c3f6990c928f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success            # Whether the execution was succesful
    string error_message    # Error message if the execution was unsuccessful
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ExecuteTstResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    if (msg.error_message !== undefined) {
      resolved.error_message = msg.error_message;
    }
    else {
      resolved.error_message = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: ExecuteTstRequest,
  Response: ExecuteTstResponse,
  md5sum() { return '44f7b4ced43e85a05e62b2b38ffc3b46'; },
  datatype() { return 'air_lab3/ExecuteTst'; }
};
